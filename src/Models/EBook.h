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
    : Book(std::move(title), std::move(author), std::move(publisher), year), mReaders(AVector<_<Reader>>()) {}

    EBook(EBook&& other) noexcept : Book(std::move(other)), mReaders(std::move(other.mReaders)) {}

    ~EBook() override = default;

    AString const& getBookContent() override;

    [[nodiscard]] AVector<_<Reader>> const& readers() const noexcept { return mReaders; }

    EBook& addReader(_<Reader> reader) noexcept { mReaders.push_back(std::move(reader)); return *this; }
    EBook& setTitle(AString title) noexcept override { Book::setTitle(std::move(title)); return *this; }
    EBook& setAuthor(AString author) noexcept override { Book::setAuthor(std::move(author)); return *this; }
    EBook& setPublisher(AString publisher) noexcept override { Book::setPublisher(std::move(publisher)); return *this; }
    EBook& setYear(const int year) noexcept override { Book::setYear(year); return *this; }
private:
    AVector<_<Reader>> mReaders;
};

