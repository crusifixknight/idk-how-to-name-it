//
// Created by crusifixknight on 6/4/2026.
//
#pragma once

#include "Book.h"
#include "Reader.h"

class PrintedBook : public Book {
public:
    PrintedBook(AString title, AString author, AString publisher, const int year, const int countOfPages) noexcept
        : Book(std::move(title), std::move(author), std::move(publisher), year),
        mIsBooked(false), mCountOfPages(countOfPages), mBookedBy(nullptr) {}

    PrintedBook(PrintedBook&& other) noexcept : Book(std::move(other)),
    mIsBooked(other.mIsBooked), mCountOfPages(other.mCountOfPages) {
        other.mCountOfPages = 0;
    }

    ~PrintedBook() override = default;

    void setBookInfo(AString, AString, AString, int, bool, int);

    [[nodiscard]] AProperty<bool> isBooked() const noexcept { return mIsBooked; }
    [[nodiscard]] AProperty<int> countOfPages() const noexcept { return mCountOfPages; }
    [[nodiscard]] AProperty<_<Reader>> const& bookedBy() const noexcept { return mBookedBy; }

    PrintedBook& setCountOfPages(const int value) noexcept { mCountOfPages = value; return *this; }
    PrintedBook& setBookedBy(_<Reader> value) noexcept;
    PrintedBook& setTitle(AString title) noexcept override { Book::setTitle(std::move(title)); return *this; }
    PrintedBook& setAuthor(AString author) noexcept override { Book::setAuthor(std::move(author)); return *this; }
    PrintedBook& setPublisher(AString publisher) noexcept override { Book::setPublisher(std::move(publisher)); return *this; }
    PrintedBook& setYear(const int year) noexcept override { Book::setYear(year); return *this; }
private:
    AProperty<bool> mIsBooked;
    AProperty<int> mCountOfPages;
    AProperty<_<Reader>> mBookedBy;
};

