//
// Created by crusifixknight on 6/5/2026.
//

#include "Library.h"

_<Reader> Library::findReader(AString const& searchName) noexcept {
    auto predicate = [searchName](_<Reader> const& r) noexcept { return r->name().contains(searchName); };
    const auto reader = mReaders.findIf(predicate);

    return reader ? *reader : nullptr;
}

_<Book> Library::findBook(AString const& searchTitle) noexcept {
    auto predicate = [searchTitle](_<Book> const& r) noexcept { return r->title().contains(searchTitle); };
    const auto book = mBooks.findIf(predicate);

    return book ? *book : nullptr;
}

bool Library::giveBook(_<Book> const& book, _<Reader> const& reader) {
    if (!book || !reader) { return false; }

    const auto printed = dynamic_pointer_cast<PrintedBook>(book);
    if (printed) {

        if (printed->isBooked()) { // If a printed book already has a reader, it cannot be transferred to another reader.
            throw std::runtime_error("Book is already booked");
        }

        printed->setBookedBy(reader);
    }
    reader->takeBook(book);

    return true;
}
bool Library::returnBook(_<Book> const& book, _<Reader> const& reader) {
    if (!book || !reader) { return false; }

    if (!reader->readerHasBook(book)) { throw std::runtime_error("Reader does not have this book"); } // Checks is reader has this book in picked vector

    const auto printed = dynamic_pointer_cast<PrintedBook>(book);
    if (printed) {
        printed->setBookedBy(nullptr);
    }
    reader->returnBook(book);


    return true;
}