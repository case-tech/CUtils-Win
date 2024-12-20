// The MIT License (MIT)
// Copyright © 2024 Case Technologies

#pragma once
#include "Common.hpp"

namespace CUtils
{
    class DateTime
    {
    public:
        DateTime();
        DateTime(time_t time);

        std::string GetCurrentDateTime() const;
        std::string GetCurrentDate()     const;
        std::string GetCurrentTime()     const;

        void   SetTime(time_t time);
        time_t GetTime() const;

        std::string Format(const std::string& format) const;

        bool operator==(const DateTime& other) const;
        bool operator!=(const DateTime& other) const;
        bool operator <(const DateTime& other) const;
        bool operator >(const DateTime& other) const;
        bool operator<=(const DateTime& other) const;
        bool operator>=(const DateTime& other) const;

    private:
        time_t currentTime_;
    };
}
