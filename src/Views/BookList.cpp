
#include "Helpers/BookViewProvider.h"
#include "BookList.h"
#include "CreateBookWindow.h"
#include "UserList.h"
#include "Models/Library.h"
#include <AUI/Util/Declarative/Containers.h>
#include <AUI/View/AForEachUI.h>
#include <AUI/View/ATextField.h>
#include <AUI/View/AButton.h>

using namespace declarative;
using namespace ass;



BookList::BookList() {
    setContents(Vertical {
      _new<ATextField>(),
      AUI_DECLARATIVE_FOR(i, *StaticElements::library->books(), AVerticalLayout) {
            return BookViewProvider::createCompactView(i);
      },
      SpacerExpanding(),
      Horizontal {

        Button {
          .content = Label { "Add new book" },
            .onClick = [this] {
                _new<CreateBookWindow>()->show();
            }
        },
        SpacerExpanding(),
          Button {
              .content = Label { "To Readers " },
              .onClick = [this] {
                  this->close();
                  _new<UserList>()->show();
              }
          } ,
      } });
}