#include <AUI/Platform/Entry.h>
#include "MainWindow.h"
#include "MyUpdater.h"
#include <BookList.h>
#include <Models/Library.h>
#include <Models/EBook.h>
#include <UserList.h>
#include <BookAdvanced.h>

AUI_ENTRY {

    auto library = _new<Library>();
    library->addBook(_new<EBook>("1984", "George Orwell", "Beba", 1488));
    //_new<BookList>(library->books())->show();


    //_new<UserList>(library->readers())->show();

    _new<BookAdvanced>(library->books()[0]);
    return 0;
};
