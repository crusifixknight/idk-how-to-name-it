#include "BookList.h"

#include "BookViewProvider.h"
#include "CreateBookWindow.h"
#include "UserList.h"
#include <AUI/Util/Declarative/Containers.h>
#include <AUI/View/AForEachUI.h>
#include <AUI/View/ATextField.h>
#include <AUI/View/AButton.h>

using namespace declarative;
using namespace ass;



BookList::BookList(_<Library> library): mLibrary(std::move(library)) {
    setContents(Vertical {
      _new<ATextField>(),
      AUI_DECLARATIVE_FOR(i, *mLibrary->books(), AVerticalLayout) {
            return BookViewProvider::createCompactView(i, mLibrary);
      },
      SpacerExpanding(),
      Horizontal {

        Button {
          .content = Label { "Add new book" },
            .onClick = [this] {
                if (mCreateBookWindow)
                    mCreateBookWindow->close();
                mCreateBookWindow = _new<CreateBookWindow>(mLibrary);
                mCreateBookWindow->show();
            }
        },
        SpacerExpanding(),
          Button {
              .content = Label { "To Readers " },
              .onClick = [this] {
                  this->close();
                  _new<UserList>(mLibrary)->show();
              }
          } ,
      } });
}