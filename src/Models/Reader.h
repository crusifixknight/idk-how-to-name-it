//
// Created by crusifixknight on 6/5/2026.
//
#pragma once

#include <AUI/Common/AString.h>
#include <AUI/Common/AVector.h>
#include "Book.h"

#include <AUI/Common/AProperty.h>

class Reader {
public:
    Reader(AString name) noexcept : mName(std::move(name)) {}
    Reader(Reader&& reader) noexcept : mName(std::move(reader.mName)) {}

    [[nodiscard]] AString const& name() const noexcept { return mName; }
    [[nodiscard]] AProperty<AVector<_<Book>>> const& books() const noexcept { return mPickedBooks; }
    [[nodiscard]] bool readerHasBook(_<Book> const& book) noexcept;

    Reader& takeBook(_<Book> const& book) noexcept { mPickedBooks.writeScope()->push_back(book); return *this; }
    Reader& returnBook(_<Book> const& book) noexcept;
    Reader& setName(AString const& name) noexcept { mName = name; return *this; }
private:
    AString mName;
    AProperty<AVector<_<Book>>> mPickedBooks;
};