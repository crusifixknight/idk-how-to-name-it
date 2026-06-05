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

    [[nodiscard]] AString const& title() const noexcept { return mTitle; }
    [[nodiscard]] AString const& author() const noexcept { return mAuthor; }
    [[nodiscard]] AString const& publisher() const noexcept { return mPublisher; }
    [[nodiscard]] int year() const noexcept { return mYear; }
private:
    AString mTitle;
    AString mAuthor;
    AString mPublisher;
    int mYear;
};

