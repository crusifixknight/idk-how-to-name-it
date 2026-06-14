#include "BookAdvanced.h"
#include "Models/EBook.h"
#include "Models/AudioBook.h"
#include "Models/PrintedBook.h"
#include <AUI/Util/Declarative/Containers.h>
#include <AUI/View/ALabel.h>

using namespace declarative;
using namespace ass;

BookAdvanced::BookAdvanced(_<Book> book) : mBook(std::move(book)) {

    setContents(Horizontal{
        Vertical{
            Label {"Name: "},
            Label {mBook->title()}
            },
        Vertical{
            Label {"Author: "},
            Label {mBook->author()}
            },
        Vertical{
            Label {"Publisher: "},
            Label {mBook->publisher()}
            },
        Vertical{
            Label {"Year: "},
            Label {"{}"_format(mBook->year())}
            },
        Huyni()
    });

}

_<AView> BookAdvanced::Huyni() const {
    const auto ebook = std::dynamic_pointer_cast<EBook>(mBook);
    const auto audiobook = std::dynamic_pointer_cast<AudioBook>(mBook);
    const auto printedbook = std::dynamic_pointer_cast<PrintedBook>(mBook);
    if (audiobook) {
        return  Vertical{
            Label {"Duration: "},
            Label {"{}"_format(audiobook->duration())}
        };
    }
    if (printedbook) {
        return Horizontal {
            Vertical{
            Label {"Count of pages: "},
            Label {"{}"_format(printedbook->countOfPages())}
            },
            Vertical{
            Label {"Is booked? "},
            Label {"{}"_format(printedbook->isBooked())}
            },
            Vertical{
            Label {"Booked by: "},
            Label {"{}"_format(printedbook->bookedBy()->name())}
            }
        };
    }
    return nullptr;
}
