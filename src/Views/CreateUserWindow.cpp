//
// Created by crusifixknight on 6/15/2026.
//

#include "CreateUserWindow.h"

#include "Helpers/StaticElements.h"

#include <AUI/ASS/ASS.h>
#include <AUI/Util/Declarative/Containers.h>
#include <AUI/View/AButton.h>
#include <AUI/View/ATextField.h>

using namespace declarative;

CreateUserWindow::CreateUserWindow() {
    auto tf = _new<ATextField>();
    mButton = _new<AButton>();

    mButton->setContents(
        Centered{
            Label{ "Create User"}
        }
    );

    validateName();

    connect(mButton->clicked, [this] {
       auto newReader = _new<Reader>(mName.value());
       StaticElements::library->addReader(std::move(newReader));
        this->close();
    });

    biConnect(mName, tf->text());
    connect(mName.changed, AUI_SLOT(this)::validateName);
    setContents(
        Centered{
            Vertical{
                tf,
                mButton
            } AUI_OVERRIDE_STYLE { LayoutSpacing { 4_dp}}
        }
    );
}

void CreateUserWindow::validateName() {
    if (mName.value().empty()) mButton->setDisabled();
    else mButton->setEnabled();
}