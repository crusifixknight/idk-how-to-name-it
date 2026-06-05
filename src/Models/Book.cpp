//
// Created by crusifixknight on 6/4/2026.
//

#include "Book.h"

void Book::setBookInfo(AString title, AString author, AString publisher, const int year) {
    mTitle = std::move(title);
    mAuthor = std::move(author);
    mPublisher = std::move(publisher);
    mYear = year;
}
