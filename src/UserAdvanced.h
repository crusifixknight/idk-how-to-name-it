#pragma once

#include "Models/Library.h"

#include <AUI/Platform/AWindow.h>
#include "Models/Reader.h"


class UserAdvanced : public AWindow {
public:
    UserAdvanced(const _<Library>&, _<Reader>);


private:
    _<Library> mLibrary;
    _<Reader> mReader;
};