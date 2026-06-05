//
// Created by crusifixknight on 6/4/2026.
//
#pragma once

#include "Book.h"

class PrintedBook : public Book {
public:
    PrintedBook(AString title, AString author, AString publisher, const int year, const int countOfPages,
        const bool isBooked) noexcept
        : Book(std::move(title), std::move(author), std::move(publisher), year),
        mIsBooked(isBooked), mCountOfPages(countOfPages) {}

    ~PrintedBook() override = default;

    AString const& getBookContent() override;

    [[nodiscard]] bool isBooked() const noexcept { return mIsBooked;};
    [[nodiscard]] int countOfPages() const noexcept { return mCountOfPages;};
private:
    bool mIsBooked;
    int mCountOfPages;
};

