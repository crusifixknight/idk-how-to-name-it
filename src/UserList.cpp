#include "UserList.h"

#include "BookList.h"
#include "StaticElements.h"
#include "UserAdvanced.h"
#include "Models/Reader.h"

#include <AUI/Util/Declarative/Containers.h>
#include <AUI/View/AForEachUI.h>
#include <AUI/View/ATextField.h>
#include <AUI/View/AButton.h>

using namespace declarative;
using namespace ass;

UserList::UserList() {
    setContents(Vertical {
      _new<ATextField>(),
      AUI_DECLARATIVE_FOR(i, *StaticElements::library->readers(), AVerticalLayout) {
          return Button {
               .content =
                   Label { "{}"_format(i->name()) }
                   AUI_OVERRIDE_STYLE {
                       BackgroundSolid { AColor::GRAY.lighter(0.7f) },
                       BorderRadius { 8_dp },
                       Margin { 3_dp },
                       Padding { 4_dp }
               },
               .onClick = [this, &i] {
                   ALogger::debug("clicked");
                   openUserAdvanced(i);
               }
          } AUI_OVERRIDE_STYLE {
           BackgroundSolid { AColor::GRAY.lighter(0.7f) },
           BorderRadius { 8_dp },
           Margin { 3_dp },
           Padding { 4_dp }
       };

      },
      SpacerExpanding(),
      Horizontal {

        Button {
          .content = Label { "Add new reader" },

        },
        SpacerExpanding(),
        Button {
          .content = Label { "To Books " },
            .onClick = [this] {
                this->close();
                _new<BookList>()->show();
            }

        },
      } });
}
void UserList::openUserAdvanced(const _<Reader> reader) {
    _new<UserAdvanced>(reader)->show();
};
