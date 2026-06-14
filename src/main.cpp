#include <AUI/Platform/Entry.h>
#include "MainWindow.h"
#include "MyUpdater.h"
#include <BookList.h>
#include <Models/Library.h>
#include <Models/EBook.h>

AUI_ENTRY {
    //auto updater = _new<MyUpdater>();
    //updater->handleStartup(args);

    //_new<MainWindow>(std::move(updater))->show();
    auto library = _new<Library>();
    library->addBook(_new<EBook>("1984", "George Orwell", "Beba", 1488));
    _new<BookList>(library->books())->show();
    return 0;
};
