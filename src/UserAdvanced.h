#pragma once


#include <AUI/Platform/AWindow.h>
#include "Models/Reader.h"


class UserAdvanced : public AWindow {
public:
    UserAdvanced(_<Reader> reader);


private:
    _<Reader> mReader;
};