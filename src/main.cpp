#include "BookList.h"

#include <AUI/Platform/Entry.h>
#include "MyUpdater.h"
#include "UserList.h"

#include <Models/Library.h>
#include <Models/EBook.h>
#include <BookAdvanced.h>
#include <Models/AudioBook.h>
#include <Models/PrintedBook.h>

AUI_ENTRY {
    auto readers = AVector<_<Reader>> {
        _new<Reader>("Michael"),
        _new<Reader>("John"),
        _new<Reader>("Jane"),
        _new<Reader>("Pablo")
    };
    auto books = AVector<_<Book>> {
        _new<AudioBook>("1984", "George Orwell", "Secker & Warburg", 1949, std::chrono::duration<double>(3600.0)),
        _new<AudioBook>("Brave New World", "Aldous Huxley", "Chatto & Windus", 1932, std::chrono::duration<double>(4500.0)),
        _new<EBook>("The Great Gatsby", "F. Scott Fitzgerald", "Charles Scribner's Sons", 1925),
        _new<EBook>("Moby Dick", "Herman Melville", "Harper & Brothers", 1851),
        _new<PrintedBook>("War and Peace", "Leo Tolstoy", "The Russian Messenger", 1869, 1225),
        _new<PrintedBook>("Crime and Punishment", "Fyodor Dostoevsky", "The Russian Messenger", 1866, 671)
    };

    auto library = _new<Library>(books, readers);
    _new<UserList>(library)->show();
    // _new<BookList>(library->books())->show();
    return 0;
};
