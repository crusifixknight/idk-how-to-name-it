#include "UserAdvanced.h"
#include "Models/Reader.h"
#include "Helpers/StaticElements.h"

#include <AUI/Util/Declarative/Containers.h>
#include <AUI/View/ALabel.h>
#include <AUI/View/AForEachUI.h>
#include <AUI/View/AButton.h>

using namespace declarative;
using namespace ass;

UserAdvanced::UserAdvanced( _<Reader> reader) : mReader(std::move(reader)) {
    auto button = _new<AButton>();

    button->setContents(
        Centered{
            Label{ "Delete"}
        }
    );
    connect(button->clicked, [this] { StaticElements::library->removeReader(mReader); this->close(); } );
    button->setEnabled(mReader->books().value().empty());
    connect(mReader->books().changed, [this, button] {
        button->setEnabled(mReader->books().value().empty());
    });

    setContents(Horizontal {
            Vertical {
                Label { "Name: " },
                Label { mReader->name() }
            },
            Vertical {
                Label { "Picked Books: " },
                AUI_DECLARATIVE_FOR(book, *mReader->books(), AVerticalLayout) {
                    return Horizontal {
                        Label { "Book: {}"_format(book->title().value()) }
                            AUI_OVERRIDE_STYLE { Expanding { true }, Margin { 0, 5_dp, 0, 0}},
                        Button {
                            .content = Label { "Return" },
                            .onClick = [this, book] {
                                if (StaticElements::library->returnBook(book, mReader)) {
                                    ALogger::debug("Book returned: {}"_format(book->title().value()));
                                } else {
                                    ALogger::warn("Failed to return book: {}"_format(book->title().value()));
                                }
                            }
                        }
                    };
                },
                SpacerExpanding(),
                button
                
            }
        } AUI_OVERRIDE_STYLE { LayoutSpacing { 15_dp } }
    );
}
