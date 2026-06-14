#pragma once

#include <AUI/Platform/AWindow.h>
#include "Models/Book.h"


class BookList : public AWindow {
public:
    BookList(AProperty<AVector<_<Book>>>);

private:
    AProperty<AVector<_<Book>>> mBooks;
};