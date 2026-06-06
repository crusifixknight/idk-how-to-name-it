//
// Created by crusifixknight on 6/4/2026.
//

#include "PrintedBook.h"

AString const& PrintedBook::getBookContent() {
    return "some book content";
}

void PrintedBook::setBookInfo(AString title, AString author, AString publisher, const int year,
    const bool isBooked, const int countOfPages) {
    Book::setBookInfo(std::move(title), std::move(author), std::move(publisher), year);
    mIsBooked = isBooked;
    mCountOfPages = countOfPages;
}
PrintedBook& PrintedBook::setBookedBy(_<Reader> value) noexcept {
    mIsBooked = static_cast<bool>(value);
    mBookedBy = std::move(value);

    return *this;
}


