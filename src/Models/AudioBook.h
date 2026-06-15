//
// Created by crusifixknight on 6/5/2026.
//
#pragma once

#include "Book.h"

using Duration = std::chrono::duration<double>;
class AudioBook: public Book {
public:
    AudioBook(AString title, AString author, AString publisher, const int year, const Duration duration) noexcept
        : Book(std::move(title), std::move(author), std::move(publisher), year), mDuration(duration) {}

    AudioBook(AudioBook&& other) noexcept
    : Book(std::move(other)), mDuration(other.mDuration) {
        other.mDuration = Duration();
    }

    ~AudioBook() override = default;

    AString const& getBookContent() override;

    [[nodiscard]] Duration const& duration() const noexcept { return mDuration; }

    AudioBook& setDuration(const Duration duration) noexcept { mDuration = duration; return *this; }
    AudioBook& setTitle(AString title) noexcept override { Book::setTitle(std::move(title)); return *this; }
    AudioBook& setAuthor(AString author) noexcept override { Book::setAuthor(std::move(author)); return *this; }
    AudioBook& setPublisher(AString publisher) noexcept override { Book::setPublisher(std::move(publisher)); return *this; }
    AudioBook& setYear(const int year) noexcept override { Book::setYear(year); return *this; }
private:
    AProperty<Duration> mDuration;
};
