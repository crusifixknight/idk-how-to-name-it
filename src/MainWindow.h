#pragma once

#include <AUI/Platform/AWindow.h>
#include "MyUpdater.h"

class MainWindow: public AWindow {
public:
    MainWindow(_<MyUpdater> updater);

private:
    _<MyUpdater> mUpdater;
};
