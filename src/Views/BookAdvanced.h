#pragma once

#include "Models/Library.h"
#include "Models/Reader.h"
#include "Models/Book.h"

#include <AUI/Platform/AWindow.h>
#include <AUI/View/AButton.h>

using namespace declarative;
class BookAdvanced : public AWindow {
public:
    BookAdvanced(_<Book>);
    _<AView> Huyni() const noexcept;

    ~BookAdvanced() override = default;
    
private:
    _<Book> mBook;
    _<AButton> mButton;

    struct State {
        AProperty<_<Reader>> mSelectedReader = nullptr;
        AProperty<AVector<_<Reader>>> mReaders;
    };
    void ParamList();
    void ParamListEdit();

    void buttonControl(_<Reader> const&) noexcept;
};