#include "UserList.h"

#include "BookList.h"
#include "UserAdvanced.h"
#include "Models/Reader.h"

#include <AUI/Util/Declarative/Containers.h>
#include <AUI/View/AForEachUI.h>
#include <AUI/View/ATextField.h>
#include <AUI/View/AButton.h>

using namespace declarative;
using namespace ass;

UserList::UserList(_<Library> library) : mLibrary(std::move(library)) {
    setContents(Vertical {
      _new<ATextField>(),
      AUI_DECLARATIVE_FOR(i, *mLibrary->readers(), AVerticalLayout) {
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
                _new<BookList>(mLibrary)->show();
            }

        },
      } });
}
void UserList::openUserAdvanced(const _<Reader> reader) {
    _new<UserAdvanced>(mLibrary, reader)->show();
};
