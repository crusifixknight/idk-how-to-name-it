//
// Created by crusifixknight on 6/4/2026.
//
#pragma once

#include <AUI/Common/AString.h>

class Book {
public:
    Book(AString title, AString author, AString publisher, const int year) noexcept
        : mTitle(std::move(title)), mAuthor(std::move(author)), mPublisher(std::move(publisher)), mYear(year) {}

    Book(Book&& other) noexcept : mTitle(std::move(other.mTitle)), mAuthor(std::move(other.mAuthor)),
    mPublisher(std::move(other.mPublisher)), mYear(other.mYear) {
        other.mYear = 0;
    }

    virtual ~Book() = default;

    virtual AString const& getBookContent() = 0;

    void setBookInfo(AString, AString, AString, int);


    [[nodiscard]] AString const& title() const noexcept { return mTitle; }
    [[nodiscard]] AString const& author() const noexcept { return mAuthor; }
    [[nodiscard]] AString const& publisher() const noexcept { return mPublisher; }
    [[nodiscard]] int year() const noexcept { return mYear; }

    virtual Book& setTitle(AString title) noexcept { mTitle = std::move(title); return *this; }
    virtual Book& setAuthor(AString author) noexcept { mAuthor = std::move(author); return *this; }
    virtual Book& setPublisher(AString publisher) noexcept { mPublisher = std::move(publisher); return *this; }
    virtual Book& setYear(const int year) noexcept { mYear = year; return *this; }
private:
    AString mTitle;
    AString mAuthor;
    AString mPublisher;
    int mYear;
};

