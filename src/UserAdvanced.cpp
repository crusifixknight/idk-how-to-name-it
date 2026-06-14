#include "UserAdvanced.h"
#include <AUI/Util/Declarative/Containers.h>
#include <AUI/View/ALabel.h>
#include "Models/Reader.h"
#include <AUI/View/AForEachUI.h>
#include <AUI/View/AButton.h>

using namespace declarative;
using namespace ass;

UserAdvanced::UserAdvanced(_<Reader> reader): mReader(std::move(reader)) {
    setContents(Horizontal{
        Vertical{
            Label {"Name: "},
            Label {mReader->name()}
            },
        Vertical{
            Label {"Picked Books: "},
            AUI_DECLARATIVE_FOR(i, mReader->books(), AVerticalLayout) {
            return Label { "Book: {}"_format(i->title()) };
                },
            },
      SpacerExpanding(),
        Vertical{
            SpacerExpanding(),
                Button {
                    .content = Label { "Add new book" },

                },
                Button {
                    .content = Label { "Edit" },

                },
                Button {
                    .content = Label { "Exit" },

                },
        }
    } AUI_OVERRIDE_STYLE { LayoutSpacing { 15_dp } });}
