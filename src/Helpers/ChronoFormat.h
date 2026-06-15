#pragma once
#include <chrono>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>

class ChronoFormat {
public:
    static std::chrono::duration<double> parseDuration(const std::string& str) {
        int hours = 0, minutes = 0, seconds = 0;
        char colon1, colon2;

        std::istringstream iss(str);
        if (iss >> hours >> colon1 >> minutes >> colon2 >> seconds && colon1 == ':' && colon2 == ':' && hours >= 0 &&
            minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60) {
            return std::chrono::hours(hours) + std::chrono::minutes(minutes) + std::chrono::seconds(seconds);
        } else {
            throw std::invalid_argument("Invalid time format, expected HH:MM:SS");
        }
    }
};