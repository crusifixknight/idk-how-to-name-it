//
// Created by crusifixknight on 6/5/2026.
//
#pragma once

#include "Book.h"
#include "Reader.h"
#include "PrintedBook.h"
#include <AUI/Common/AProperty.h>
#include <AUI/Common/AVector.h>


class Library {
public:
    Library(AVector<_<Book>> books, AVector<_<Reader>> readers) noexcept
    : mBooks(std::move(books)), mReaders(std::move(readers)) {}

    Library() : mBooks(AProperty<AVector<_<Book>>>()), mReaders(AProperty<AVector<_<Reader>>>() ) {}

    Library(Library&& library) noexcept : mBooks(std::move(library.mBooks)), mReaders(std::move(library.mReaders)) {}

    [[nodiscard]] AProperty<AVector<_<Book>>> const& books() const noexcept { return mBooks; }
    [[nodiscard]] AProperty<AVector<_<Reader>>> const& readers() const noexcept { return mReaders; }

    Library& addBook(_<Book> book) noexcept { mBooks.writeScope()->emplace_back(std::move(book)); return *this; }
    Library& removeBook(_<Book> const& book) noexcept { mBooks.writeScope()->removeAll(book); return *this; }

    Library& addReader(_<Reader> reader) noexcept { mReaders.writeScope()->push_back(std::move(reader)); return *this; }
    Library& removeReader(_<Reader> const& reader) noexcept { mReaders.writeScope()->removeAll(reader); return *this; }

    _<Reader> findReader(AString const& searchName) noexcept;
    _<Book> findBook(AString const& searchTitle) noexcept;

    bool giveBook(_<Book> const& book, _<Reader> const& reader);
    bool returnBook(_<Book> const& book, _<Reader> const& reader);

private:
    AProperty<AVector<_<Book>>> mBooks;
    AProperty<AVector<_<Reader>>> mReaders;

};