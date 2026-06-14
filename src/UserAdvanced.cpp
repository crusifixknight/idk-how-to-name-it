#include "UserAdvanced.h"
#include <AUI/Util/Declarative/Containers.h>
#include <AUI/View/ALabel.h>
#include "Models/Reader.h"
#include <AUI/View/AForEachUI.h>
#include <AUI/View/AButton.h>

using namespace declarative;
using namespace ass;

UserAdvanced::UserAdvanced(_<Library> const& library, _<Reader> reader): mLibrary(library), mReader(std::move(reader)) {
    setContents(Horizontal {
            Vertical {
                Label { "Name: " },
                Label { mReader->name() }
            },
            Vertical {
                Label { "Picked Books: " },
                AUI_DECLARATIVE_FOR(book, *mReader->books(), AVerticalLayout) {
                    return Horizontal {
                        Label { "Book: {}"_format(book->title()) }
                            AUI_OVERRIDE_STYLE { Expanding { true }, Margin { 0, 5_dp, 0, 0}},
                        Button {
                            .content = Label { "Return" },
                            .onClick = [this, book] {
                                if (mLibrary->returnBook(book, mReader)) {
                                    ALogger::debug("Book returned: {}"_format(book->title()));
                                } else {
                                    ALogger::warn("Failed to return book: {}"_format(book->title()));
                                }
                            }
                        }
                    };
                }
            }
        } AUI_OVERRIDE_STYLE { LayoutSpacing { 15_dp } }
    );
}
