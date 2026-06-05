//
// Created by crusifixknight on 6/5/2026.
//
#pragma once

#include "Book.h"
#include "Reader.h"

#include <AUI/Common/AVector.h>

class EBook: public Book {
public:
    EBook(AString title, AString author, AString publisher, const int year) noexcept
    : Book(std::move(title), std::move(author), std::move(publisher), year), mReaders(AVector<Reader>()) {}

    EBook(EBook&& other) noexcept : Book(std::move(other)), mReaders(std::move(other.mReaders)) {}

    ~EBook() override = default;

    AString const& getBookContent() override;

    [[nodiscard]] AVector<Reader> const& readers() const noexcept { return mReaders; }
private:
    AVector<Reader> mReaders;
};

