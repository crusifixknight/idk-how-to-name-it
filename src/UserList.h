#pragma once

#include "Models/Library.h"

#include <AUI/Platform/AWindow.h>
#include "Models/Reader.h"

class UserList : public AWindow {
public:
    UserList(_<Library>);

private:
    _<Library> mLibrary;
    void openUserAdvanced(_<Reader>);
};