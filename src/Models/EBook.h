//
// Created by crusifixknight on 6/5/2026.
//
#pragma once

#include "Book.h"
#include "Reader.h"

class EBook: public Book {
public:
    EBook(AString title, AString author, AString publisher, const int year) noexcept
    : Book(std::move(title), std::move(author), std::move(publisher), year) {}

    EBook(EBook&& other) noexcept : Book(std::move(other)) {}

    ~EBook() override = default;

    EBook& setTitle(AString const& title) noexcept override { Book::setTitle(title); return *this; }
    EBook& setAuthor(AString const& author) noexcept override { Book::setAuthor(author); return *this; }
    EBook& setPublisher(AString const& publisher) noexcept override { Book::setPublisher(publisher); return *this; }
    EBook& setYear(const int year) noexcept override { Book::setYear(year); return *this; }
};

