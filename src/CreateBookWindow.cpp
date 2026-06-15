//
// Created by crusifixknight on 6/15/2026.
//

#include "CreateBookWindow.h"

#include "BookAdvanced.h"
#include "Models/AudioBook.h"
#include "Models/EBook.h"

#include <AUI/Util/Declarative/Containers.h>
#include <AUI/View/AButton.h>
#include <AUI/View/ARadioButton.h>
using namespace declarative;

CreateBookWindow::CreateBookWindow(_<Library> const& library) : mLibrary(library) {
    setContents(
        Vertical {
            Label { "Select book type"},
            Vertical{
                RadioButton{
                    .checked = AUI_REACT(selectedBookType == 0),
                    .onClick = [this] {
                        selectedBookType = 0;
                    },
                    .content = Label { "EBook"}
                },
                RadioButton{
                    .checked = AUI_REACT(selectedBookType == 1),
                    .onClick = [this] {
                        selectedBookType = 1;
                    },
                    .content = Label { "Audio book"}
                },
                RadioButton{
                    .checked = AUI_REACT(selectedBookType == 2),
                    .onClick = [this] {
                        selectedBookType = 2;
                    },
                    .content = Label { "Printed book"}
                },
            },
            Button {
                .content = Label {"Create book"},
                .onClick = { me::createBook }
            }
        } AUI_OVERRIDE_STYLE { LayoutSpacing {4_dp} }
    );
}

void CreateBookWindow::createBook() {
    _<Book> newBook;
    const std::chrono::year_month_day ymd { std::chrono::floor<std::chrono::days>(std::chrono::system_clock::now()) };
    int currentYear = static_cast<int>(ymd.year());
    switch (selectedBookType) {
        case 0:
            newBook = _new<EBook>("Empty", "Empty", "Empty", currentYear);
            break;
        case 1:
            newBook = _new<AudioBook>("Empty", "Empty", "Empty", currentYear, std::chrono::duration<double>(0));
            break;
        case 2:
            newBook = _new<PrintedBook>("Empty", "Empty", "Empty", currentYear, 0);
            break;
        default:
            throw std::runtime_error("Unexpected error");
    }
    mLibrary->addBook(newBook);
    _new<BookAdvanced>(mLibrary, newBook)->show();
    this->close();
}