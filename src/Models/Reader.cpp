//
// Created by crusifixknight on 6/5/2026.
//

#include "Reader.h"

bool Reader::readerHasBook(_<Book> const& book) noexcept {
    auto predicate = [book](_<Book> const& pickedBook) noexcept { return pickedBook == book; };
    const auto result = mPickedBooks.findIf(predicate);
    return result != nullptr;
}

Reader& Reader::returnBook(_<Book> const& book) noexcept {
    auto predicate = [book](_<Book> const& pickedBook) noexcept { return pickedBook == book; };
    mPickedBooks.removeIf(predicate);
    return *this;
}