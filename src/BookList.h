#pragma once

#include <AUI/Platform/AWindow.h>
#include "Models/Book.h"
#include "Models/Library.h"

class BookList : public AWindow {
public:
    BookList(_<Library>);

    ~BookList() override = default;
private:
    _<Library> mLibrary;
    void createBook();
};