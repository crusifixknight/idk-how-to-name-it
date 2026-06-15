#pragma once

#include "Models/Library.h"
#include "Models/Reader.h"
#include "Models/Book.h"

#include <AUI/Platform/AWindow.h>
#include <AUI/View/AButton.h>
#include <AUI/View/ATextField.h>

using namespace declarative;
class BookAdvanced : public AWindow {
public:
    BookAdvanced(_<Book>);
    _<AView> Huyni() const noexcept;
    _<AView> HuyniEdit() noexcept;

    ~BookAdvanced() override = default;
    
private:
    _<Book> mBook;
    _<AButton> mButton;

    _<ATextField> tfName;
    _<ATextField> tfAuthor;
    _<ATextField> tfYear;
    _<ATextField> tfPublisher;

    _<ATextField> tfCountOfPages;
    _<ATextField> tfDuration;

    struct State {
        AProperty<_<Reader>> mSelectedReader = nullptr;
        AProperty<AVector<_<Reader>>> mReaders;
    };
    void ParamList();
    void ParamListEdit();

    void SaveEdit();


    void buttonControl(_<Reader> const&) noexcept;
};