//
// Created by crusifixknight on 6/5/2026.
//
#pragma once

#include <AUI/Common/AString.h>

class Reader {
public:
    Reader(AString name) noexcept : mName(std::move(name)) {}
    Reader(Reader&& reader) noexcept : mName(std::move(reader.mName)) {}

    [[nodiscard]] AString const& name() const noexcept { return mName; }
private:
    AString mName;

};
