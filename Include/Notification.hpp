// The MIT License (MIT)
// Copyright © 2024 Case Technologies

#pragma once
#include "Common.hpp"

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