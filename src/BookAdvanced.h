#pragma once

#include "Models/Library.h"
#include "Models/Reader.h"

#include <AUI/Platform/AWindow.h>
#include <Models/Book.h>
#include <AUI/Util/Declarative/Containers.h>


using namespace declarative;
class BookAdvanced : public AWindow {
public:
    BookAdvanced(_<Library> const& library, _<Book>);
    _<AView> Huyni() const;

    ~BookAdvanced() override = default;
private:
    _<Book> mBook;
    _<Library> mLibrary;

    struct State {
        AProperty<_<Reader>> mSelectedReader = nullptr;
        AProperty<AVector<_<Reader>>> mReaders;
    };
};