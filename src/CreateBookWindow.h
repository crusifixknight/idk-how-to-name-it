//
// Created by crusifixknight on 6/15/2026.
//

#pragma once
#include "Models/Library.h"

#include <AUI/Platform/AWindow.h>

class CreateBookWindow : public AWindow {
public:
    CreateBookWindow();
private:
    AProperty<int> selectedBookType = 0;
    void createBook();
};
