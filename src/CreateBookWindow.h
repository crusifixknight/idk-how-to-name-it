//
// Created by crusifixknight on 6/15/2026.
//

#pragma once
#include "Models/Library.h"

#include <AUI/Platform/AWindow.h>

class CreateBookWindow : public AWindow {
public:
    CreateBookWindow(_<Library> const&);
private:
    _<Library> mLibrary;
    AProperty<int> selectedBookType = 0;
    void createBook();
};
