//
// Created by crusifixknight on 6/14/2026.
//
#pragma once

#include "Views/BookAdvanced.h"
#include "StaticElements.h"
#include "Models/AudioBook.h"
#include "Models/Book.h"
#include "Models/EBook.h"
#include "Models/PrintedBook.h"

#include <AUI/Util/Declarative/Containers.h>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <AUI/View/AButton.h>

using namespace declarative;
using namespace ass;

using Duration = std::chrono::duration<double>;
class BookViewProvider {
public:
    static _<AView> createCompactView(_<Book> const& book) {
        return Button {
            .content = Vertical {
                Label { "{}, {}"_format(book->title().value(), getFormatString(book)) }
                AUI_OVERRIDE_STYLE{ FontSize{ 14_dp }, LineHeight { 3_dp } },
            Label { getDetailsLine(book) }
                AUI_OVERRIDE_STYLE{ FontSize{ 11_dp }, TextColor{ AColor::GRAY } }
            } AUI_OVERRIDE_STYLE {
                Expanding {}
            },
            .onClick = [&book] {
                ALogger::debug("clicked");
                _new<BookAdvanced>(book)->show();
            }
        } AUI_OVERRIDE_STYLE {
            BackgroundSolid { AColor::GRAY.lighter(0.7f) },
            BorderRadius { 8_dp },
            Margin { 3_dp },
            Padding { 4_dp }
        };
    }

    static AString formatDuration(const Duration duration) {
        const auto hms = std::chrono::hh_mm_ss(duration);

        std::ostringstream oss;
        oss << std::setfill('0')
            << std::setw(2) << hms.hours().count() << ":"
            << std::setw(2) << hms.minutes().count() << ":"
            << std::setw(2) << hms.seconds().count();

        return oss.str();
    }

private:
    static AString getFormatString(const _<Book>& book) {
        if (const auto ebook = std::dynamic_pointer_cast<EBook>(book)) {
            return "EBook";
        }
        if (const auto audiobook = std::dynamic_pointer_cast<AudioBook>(book)) {
            return "Audio Book, Duration: {}"_format(formatDuration(audiobook->duration()));
        }
        if (const auto printed = std::dynamic_pointer_cast<PrintedBook>(book)) {
            return "Printed Book";
        }
        return "Unknown";
    }

    static AString getDetailsLine(const _<Book>& book) {
        AString baseInfo = "Author: {}, Publisher: {}, Year: {}"_format(
            book->author().value(), book->publisher().value(), book->year().value()
        );

        if (const auto printed = std::dynamic_pointer_cast<PrintedBook>(book)) {
            return "{}, Pages: {}"_format(baseInfo, printed->countOfPages());
        }
        return baseInfo;
    }

};