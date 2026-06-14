#include "BookList.h"

#include "Models/EBook.h"

#include <AUI/Util/Declarative/Containers.h>
#include <AUI/View/AForEachUI.h>

using namespace declarative;


BookList::BookList(AProperty<AVector<_<Book>>> Books): mBooks(std::move(Books)) {
	setContents(Vertical{
	    AUI_DECLARATIVE_FOR(i, *mBooks, AVerticalLayout) {
                const auto ebook = dynamic_pointer_cast<EBook>(i);
	        if (ebook) {
	            return Label { "Ebook: {}"_format(i->title())};
	        }
	        //TODO: Add for other books
	        return Label{ "Other books" };
    }
	}); 
}
