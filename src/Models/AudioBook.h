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

    ~AudioBook() override = default;

    AString const& getBookContent() override;

    [[nodiscard]] Duration const& duration() const noexcept { return mDuration; }
private:
    Duration mDuration;
};
