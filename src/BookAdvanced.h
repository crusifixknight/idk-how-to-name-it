#pragma once


#include <AUI/Platform/AWindow.h>
#include <Models/Book.h>
#include <AUI/Util/Declarative/Containers.h>


using namespace declarative;
class BookAdvanced : public AWindow {
public:
    BookAdvanced(_<Book> book);
    Horizontal Huyni();

private:
    _<Book> mBook;
};