#include "BookList.h"

#include "Models/EBook.h"

#include <AUI/Util/Declarative/Containers.h>
#include <AUI/View/AForEachUI.h>
#include <AUI/View/ATextField.h>
#include <AUI/View/AButton.h>

using namespace declarative;
using namespace ass;



BookList::BookList(AProperty<AVector<_<Book>>> Books): mBooks(std::move(Books)) {
    setContents(Vertical {
      _new<ATextField>(),
      AUI_DECLARATIVE_FOR(i, *mBooks, AVerticalLayout) {
          const auto ebook = dynamic_pointer_cast<EBook>(i);
          if (ebook) {
              return Label { "Ebook: {}"_format(i->title()) };
          }
          // TODO: Add for other books
          return Label { "Other books" };
      },
      SpacerExpanding(),
      Horizontal {

        Button {
          .content = Label { "Add new book" },
          
        },
        SpacerExpanding(),
          Button {
            .content = Label { "To Readers " },
            
          } ,
      } });
};
