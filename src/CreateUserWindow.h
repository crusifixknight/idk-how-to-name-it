//
// Created by crusifixknight on 6/15/2026.
//

#pragma once
#include <AUI/Platform/AWindow.h>
#include <AUI/View/AButton.h>

class CreateUserWindow : public AWindow {
public:
    CreateUserWindow();
private:
    AProperty<AString> mName;
    _<AButton> mButton;
    void validateName();

};
