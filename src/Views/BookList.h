#pragma once

#include <AUI/Platform/AWindow.h>

class BookList : public AWindow {
public:
    BookList();

    ~BookList() override = default;
private:
    void createBook();
};