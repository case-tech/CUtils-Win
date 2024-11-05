// The MIT License (MIT)
// Copyright © 2024 Case Technologies

#pragma once
#include <memory>
#include <mutex>

namespace CUtils
{
    template <typename T>
    class Singleton 
    {
    public:
        static T& instance() 
        {
            std::call_once(initFlag, []() 
            {
                instancePtr.reset(new T());
            });
            return *instancePtr;
        }

        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;

    protected:
        Singleton() = default;
        virtual ~Singleton() = default;

    private:
        static std::unique_ptr<T> instancePtr;
        static std::once_flag initFlag;      
    };

    template <typename T>
    std::unique_ptr<T> Singleton<T>::instancePtr = nullptr;

    template <typename T>
    std::once_flag Singleton<T>::initFlag;
}