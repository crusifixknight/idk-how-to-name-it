#pragma once

#include <AUI/Platform/AWindow.h>
#include "Models/Reader.h"

class UserList : public AWindow {
public:
    UserList(AProperty<AVector<_<Reader>>>);

private:
    AProperty<AVector<_<Reader>>> mReaders;

};