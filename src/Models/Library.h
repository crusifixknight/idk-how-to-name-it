//
// Created by crusifixknight on 6/5/2026.
//
#pragma once

#include "Book.h"
#include "Reader.h"
#include "PrintedBook.h"

#include <AUI/Common/AVector.h>

class Library {
public:
    Library(AVector<_<Book>> books, AVector<_<Reader>> readers) noexcept
    : mBooks(std::move(books)), mReaders(std::move(readers)) {}

    Library() : mBooks(AVector<_<Book>>()) {}

    Library(Library&& library) noexcept : mBooks(std::move(library.mBooks)), mReaders(std::move(library.mReaders)) {}

    [[nodiscard]] AVector<_<Book>> const& books() const noexcept { return mBooks; }
    [[nodiscard]] AVector<_<Reader>> const& readers() const noexcept { return mReaders; }

    Library& addBook(_<Book> book) noexcept { mBooks.emplace_back(std::move(book)); return *this; }
    Library& addReader(_<Reader> reader) noexcept { mReaders.push_back(std::move(reader)); return *this; }
    Library& removeReader(_<Reader> const& reader) noexcept { mReaders.removeAll(reader); return *this; }

    _<Reader> findReader(AString const& searchName) noexcept;
    _<Book> findBook(AString const& searchTitle) noexcept;

    bool giveBook(_<Book> const& book, _<Reader> const& reader);
    bool returnBook(_<Book> const& book, _<Reader> const& reader);

private:
    AVector<_<Book>> mBooks;
    AVector<_<Reader>> mReaders;

};