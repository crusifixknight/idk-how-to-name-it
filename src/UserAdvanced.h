#pragma once

#include "Models/Library.h"

#include <AUI/Platform/AWindow.h>
#include "Models/Reader.h"


class UserAdvanced : public AWindow {
public:
    UserAdvanced(_<Reader>);


private:
    _<Reader> mReader;
};