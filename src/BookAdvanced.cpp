#include "BookAdvanced.h"
#include "Models/EBook.h"
#include "Models/AudioBook.h"
#include "Models/PrintedBook.h"
#include <AUI/Util/Declarative/Containers.h>
#include <AUI/View/ALabel.h>
#include <AUI/View/ASpacerExpanding.h>
#include <AUI/View/AButton.h>
#include <AUI/View/AForEachUI.h>
#include <AUI/View/ARadioButton.h>

using namespace declarative;
using namespace ass;

BookAdvanced::BookAdvanced(_<Library> const& library, _<Book> book) : mLibrary(library), mBook(std::move(book)) {
    bool isAvailable = true;
    if (auto printed = dynamic_pointer_cast<PrintedBook>(mBook)) {
        isAvailable = !printed->isBooked();
    }

    auto state = _new<State>();
    for (const auto& reader : *mLibrary->readers()) {
        state->mReaders.writeScope()->push_back(reader);
    }

    setContents(Horizontal{
        Vertical{
            Label {"Name: "},
            Label {mBook->title()}
        },
        Vertical{
            Label {"Author: "},
            Label {mBook->author()}
        },
        Vertical{
            Label {"Publisher: "},
            Label {mBook->publisher()}
        },
        Vertical{
            Label {"Year: "},
            Label {"{}"_format(mBook->year())}
        },
        Huyni(),
        Label { "Select reader:" },
        AUI_DECLARATIVE_FOR(reader, *state->mReaders, AVerticalLayout) {
            return RadioButton {
                .checked = AUI_REACT(state->mSelectedReader == reader),
                .onClick = [state, reader] {
                    state->mSelectedReader = reader;
                },
                .content = Label { reader->name() },
            };
        },
        Button {
            .content = Label { "Take book" },
            .onClick = [this, state] {
                if (state->mSelectedReader && mLibrary->giveBook(mBook, state->mSelectedReader)) {
                    ALogger::debug("Book '{}' taken by {}"_format( mBook->title(), state->mSelectedReader->value().name()));
                } else {
                    ALogger::warn("No reader selected or failed to take book");
                }
            }
        },
        SpacerExpanding(),
        Vertical{
            SpacerExpanding(),
            Button {
                .content = Label { "Edit" },

            },
            Button {
                .content = Label { "Exit" },

            },
        } AUI_OVERRIDE_STYLE { LayoutSpacing { 15_dp } }});

}

_<AView> BookAdvanced::Huyni() const {
    const auto ebook = std::dynamic_pointer_cast<EBook>(mBook);
    const auto audiobook = std::dynamic_pointer_cast<AudioBook>(mBook);
    const auto printedbook = std::dynamic_pointer_cast<PrintedBook>(mBook);
    if (audiobook) {
        return  Vertical{
            Label {"Duration: "},
            Label {"{}"_format(audiobook->duration())}
        };
    }
    if (printedbook) {

        return Horizontal {
            Vertical{
            Label {"Count of pages: "},
            Label {AUI_REACT("{}"_format(printedbook->countOfPages()))}
            },
            Vertical{
            Label {"Is booked? "},
            Label {AUI_REACT("{}"_format(printedbook->isBooked()))}
            },
            Vertical{
            Label {"Booked by: "},
            Label {AUI_REACT("{}"_format(static_cast<bool>(printedbook->bookedBy().value()) ? printedbook->bookedBy().value()->name() : "None"))}
            }
        };
    }
    return nullptr;
}
