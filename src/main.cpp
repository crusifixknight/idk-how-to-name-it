#include <AUI/Platform/Entry.h>
#include "MainWindow.h"
#include "MyUpdater.h"
#include <BookList.h>
#include <Models/Library.h>
#include <Models/EBook.h>
#include <UserList.h>
#include <BookAdvanced.h>
#include <Models/AudioBook.h>
#include <Models/PrintedBook.h>

AUI_ENTRY {

    auto library = _new<Library>();
    library->addBook(_new<AudioBook>("1984", "George Orwell", "Beba", 1488, std::chrono::duration<double>(2.5)));
    //_new<BookList>(library->books())->show();


    //_new<UserList>(library->readers())->show();

    auto a = library->books()->at(0);
    _new<BookAdvanced>(a)->show();
    return 0;
};
