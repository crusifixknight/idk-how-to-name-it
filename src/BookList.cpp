#include "BookList.h"
#include <AUI/Util/Declarative/Containers.h>
#include <AUI/View/AForEachUI.h>

using namespace declarative;


BookList::BookList(AProperty<AVector<_<Book>>> Books): mBooks(std::move(Books)) {
	setContents(Vertical{ 
		AUI_DECLARATIVE_FOR(i, *mBooks, AVerticalLayout) {
        return Label { "{}"_format(i) 
		};
    }
	}); 
}
