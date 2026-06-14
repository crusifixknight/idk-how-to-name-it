#include "UserList.h"

#include "Models/Reader.h"

#include <AUI/Util/Declarative/Containers.h>
#include <AUI/View/AForEachUI.h>
#include <AUI/View/ATextField.h>
#include <AUI/View/AButton.h>

using namespace declarative;
using namespace ass;

UserList::UserList(AProperty<AVector<_<Reader>>> Readers) : mReaders(std::move(Readers)) {
    setContents(Vertical {
      _new<ATextField>(),
      AUI_DECLARATIVE_FOR(i, *mReaders, AVerticalLayout) {
          return Button {
               .content =
                   Label { "{}"_format(i->name()) }
                   AUI_OVERRIDE_STYLE {
                       BackgroundSolid { AColor::GRAY.lighter(0.7f) },
                       BorderRadius { 8_dp },
                       Margin { 3_dp },
                       Padding { 4_dp }
               },
               .onClick = [i] {
                   ALogger::debug("clicked");
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

        },
      } });
};
