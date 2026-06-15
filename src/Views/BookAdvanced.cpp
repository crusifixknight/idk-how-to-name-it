#include "BookAdvanced.h"

#include "Helpers/BookViewProvider.h"
#include "Models/AudioBook.h"
#include "Models/PrintedBook.h"
#include <AUI/Util/Declarative/Containers.h>
#include <AUI/View/ALabel.h>
#include <AUI/View/ASpacerExpanding.h>
#include <AUI/View/AButton.h>
#include <AUI/View/AForEachUI.h>
#include <AUI/View/ARadioButton.h>
#include <AUI/ASS/ASS.h>
#include <Helpers/ChronoFormat.h>

using namespace declarative;
using namespace ass;

BookAdvanced::BookAdvanced(_<Book> book) : mBook(std::move(book)) {
    ParamList();
}

void BookAdvanced::ParamList() {
    auto state = _new<State>();
    std::copy(
        StaticElements::library->readers().value().begin(), StaticElements::library->readers().value().end(),
        std::back_inserter(state->mReaders.writeScope().value()));
    mButton = _new<AButton>();

    mButton->setContents(Stacked { Label { "Take book" } });

    connect(mButton->clicked, [this, state] {
        if (state->mSelectedReader && StaticElements::library->giveBook(mBook, state->mSelectedReader)) {
            ALogger::debug("Book '{}' taken by {}"_format(mBook->title().value(), state->mSelectedReader->value().name()));
        } else {
            ALogger::warn("No reader selected or failed to take book");
        }
    });

    if (auto printedbook = std::dynamic_pointer_cast<PrintedBook>(mBook)) {
        buttonControl(printedbook->bookedBy().value());
        connect(printedbook->bookedBy().changed, AUI_SLOT(this)::buttonControl);
    }
        setContents(Vertical {
          Vertical { Label { "Name: " }, Label { AUI_REACT(mBook->title()) } },
          Vertical { Label { "Author: " }, Label { AUI_REACT(mBook->author()) } },
          Vertical { Label { "Publisher: " }, Label { AUI_REACT(mBook->publisher()) } },
          Vertical { Label { "Year: " }, Label { AUI_REACT("{}"_format(mBook->year().value())) } }, Huyni(), Label { "Select reader:" },
          AUI_DECLARATIVE_FOR(reader, *state->mReaders, AVerticalLayout) {
              return RadioButton {
                  .checked = AUI_REACT(state->mSelectedReader == reader),
                  .onClick = [state, reader] { state->mSelectedReader = reader; },
                  .content = Label { reader->name() },
              };
          },
          mButton, SpacerExpanding(),
          Vertical {
            SpacerExpanding(),
            Button {
              .content = Label { "Edit" },
              .onClick = { me::ParamListEdit }
            },
            Button {
              .content = Label { "Delete" },
                .onClick = {me::RemoveBook }
              
            }
          } AUI_OVERRIDE_STYLE { LayoutSpacing { 20_dp } } });
}

void BookAdvanced::ParamListEdit() {
    tfName = _new<ATextField>();
    tfAuthor = _new<ATextField>();
    tfPublisher = _new<ATextField>();
    tfYear = _new<ATextField>();


    tfName->setText(mBook->title().value());
    tfAuthor->setText(mBook->author().value());
    tfPublisher->setText(mBook->publisher().value());
    tfYear->setText("{}"_format(mBook->year().value()));

    setContents(Vertical {
       Vertical { Label { "Name: " }, tfName },
       Vertical { Label { "Author: " }, tfAuthor },
       Vertical { Label { "Publisher: " }, tfPublisher },
       Vertical { Label { "Year: " }, tfYear }, HuyniEdit(),
          
       SpacerExpanding(),
          Vertical {
             SpacerExpanding(),
              Button {
                  .content = Label { "Edit" },
                  .onClick = {me::SaveEdit}
              }
          } AUI_OVERRIDE_STYLE { LayoutSpacing { 15_dp }
          }
    });
}

_<AView> BookAdvanced::Huyni() const noexcept{
    if (const auto audiobook = std::dynamic_pointer_cast<AudioBook>(mBook)) {
        return  Vertical{
            Label {"Duration: "},
            Label {"{}"_format(BookViewProvider::formatDuration(audiobook->duration()))}
        };
    }
    if (const auto printedbook = std::dynamic_pointer_cast<PrintedBook>(mBook)) {
        return Horizontal {
            Vertical{
            Label {"Count of pages: "},
            Label {"{}"_format(printedbook->countOfPages())}
            },
            Vertical{
            Label {"Booked by: "},
            Label {AUI_REACT("{}"_format(static_cast<bool>(printedbook->bookedBy().value()) ? printedbook->bookedBy().value()->name() : "None"))}
            }
        };
    }
    return nullptr;
}

void BookAdvanced::buttonControl(_<Reader> const& reader) noexcept {
    mButton->setDisabled(static_cast<bool>(reader));
}

_<AView> BookAdvanced::HuyniEdit() noexcept {
    if (const auto audiobook = std::dynamic_pointer_cast<AudioBook>(mBook)) {
        tfDuration = _new<ATextField>();
        tfDuration->setText("{}"_format(BookViewProvider::formatDuration(audiobook->duration())));
        return Vertical {
            Label { "Duration: " }, tfDuration
        };
    }
    if (const auto printedbook = std::dynamic_pointer_cast<PrintedBook>(mBook)) {
        tfCountOfPages = _new<ATextField>();
        tfCountOfPages->setText("{}"_format(printedbook->countOfPages()));
        return Horizontal {
            Vertical { Label { "Count of pages: " }, tfCountOfPages },
            
        };
    }
    return nullptr;
}

void BookAdvanced::SaveEdit() {
    if (const auto audiobook = std::dynamic_pointer_cast<AudioBook>(mBook)) {
        audiobook->setDuration(ChronoFormat::parseDuration(tfDuration->getText()));
    }
    if (const auto printedbook = std::dynamic_pointer_cast<PrintedBook>(mBook)) {
        printedbook->setCountOfPages(std::stoi(tfCountOfPages->getText()));
    }
    mBook->setTitle(tfName->getText())
        .setAuthor(tfAuthor->getText())
        .setPublisher(tfPublisher->getText())
        .setYear(std::stoi(tfYear->getText()));
    ParamList();
}

void BookAdvanced::RemoveBook() {
    for (auto& reader : *StaticElements::library->readers()) {
        if (reader->readerHasBook(mBook)) {
            reader->returnBook(mBook);
        }
    }
    StaticElements::library->removeBook(mBook);
    this->close();
}