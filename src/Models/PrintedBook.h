//
// Created by crusifixknight on 6/4/2026.
//
#pragma once

#include "Book.h"
#include "Reader.h"

class PrintedBook : public Book {
public:
    PrintedBook(AString title, AString author, AString publisher, const int year, const int countOfPages,
        const bool isBooked) noexcept
        : Book(std::move(title), std::move(author), std::move(publisher), year),
        mIsBooked(isBooked), mCountOfPages(countOfPages) {}

    PrintedBook(PrintedBook&& other) noexcept : Book(std::move(other)),
    mIsBooked(other.mIsBooked), mCountOfPages(other.mCountOfPages) {
        other.mCountOfPages = 0;
    }

    ~PrintedBook() override = default;

    AString const& getBookContent() override;
    void setBookInfo(AString, AString, AString, int, bool, int);

    [[nodiscard]] bool isBooked() const noexcept { return mIsBooked; }
    [[nodiscard]] int countOfPages() const noexcept { return mCountOfPages; }
    [[nodiscard]] _<Reader> const& bookedBy() const noexcept { return mBookedBy; }

    PrintedBook& setIsBooked(const bool value) noexcept { mIsBooked = value; return *this; }
    PrintedBook& setCountOfPages(const int value) noexcept { mCountOfPages = value; return *this; }
    PrintedBook& setBookedBy(_<Reader> value) noexcept { mBookedBy = std::move(value); return *this; }
    PrintedBook& setTitle(AString title) noexcept { Book::setTitle(std::move(title)); return *this; }
    PrintedBook& setAuthor(AString author) noexcept { Book::setAuthor(std::move(author)); return *this; }
    PrintedBook& setPublisher(AString publisher) noexcept { Book::setPublisher(std::move(publisher)); return *this; }
    PrintedBook& setYear(const int year) noexcept { Book::setYear(year); return *this; }
private:
    bool mIsBooked;
    int mCountOfPages;
    _<Reader> mBookedBy;
};

