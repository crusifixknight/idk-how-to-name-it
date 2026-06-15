#pragma once

#include "Models/Library.h"

#include <AUI/Platform/AWindow.h>
#include "Models/Reader.h"

class UserList : public AWindow {
public:
    UserList();

private:
    void openUserAdvanced(_<Reader>);
};