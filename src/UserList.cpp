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
           return Label { "Reader: {}"_format(i->name()) };

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
