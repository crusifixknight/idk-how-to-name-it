//
// Created by crusifixknight on 6/5/2026.
//

#include "Library.h"

_<Reader> Library::findReader(AString const& name) noexcept {
    auto predicate = [name](_<Reader> const& r) noexcept { return r->name() == name; };
    const auto reader = mReaders.findIf(predicate);

    return reader ? *reader : nullptr;
}

_<Book> Library::findBook(AString const& title) noexcept {
    auto predicate = [title](_<Book> const& r) noexcept { return r->title() == title; };
    const auto book = mBooks.findIf(predicate);

    return book ? *book : nullptr;
}

