//
// Created by crusifixknight on 6/5/2026.
//

#pragma once
#include "Book.h"
#include "Reader.h"

#include <AUI/Common/AVector.h>

class Library {
public:
    Library(AVector<_<Book>> books, AVector<_<Reader>> readers) noexcept
    : mBooks(std::move(books)), mReaders(std::move(readers)) {}

    Library() : mBooks(AVector<_<Book>>()) {}

    Library(Library&& library) noexcept : mBooks(std::move(library.mBooks)), mReaders(std::move(library.mReaders)) {}

    [[nodiscard]] AVector<_<Book>> const& books() const noexcept { return mBooks; }
private:
    AVector<_<Book>> mBooks;
    AVector<_<Reader>> mReaders;

};
