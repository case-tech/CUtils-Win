// The MIT License (MIT)
// Copyright © 2024 Case Technologies

#pragma once
#include <string>
#include <iostream>

#ifdef _WIN32 || _WIN64
#include <windows.h> 
#endif

namespace CUtils
{
    class Notification
    {
    public:
        enum NotificationType
        {
            TYPE_ERROR,
            TYPE_WARNING,
            TYPE_INFO
        };

        static void notify(NotificationType type, const std::string& message);
    };
}