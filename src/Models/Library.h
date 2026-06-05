//
// Created by crusifixknight on 6/5/2026.
//

#pragma once
#include "Book.h"

#include <AUI/Common/AVector.h>

class Library {
public:
    Library(AVector<_<Book>> books) noexcept : mBooks(std::move(books)) {}
    Library() : mBooks(AVector<_<Book>>()) {};

    [[nodiscard]] AVector<_<Book>> const& books() const noexcept { return mBooks; };
private:
    AVector<_<Book>> mBooks;

};
