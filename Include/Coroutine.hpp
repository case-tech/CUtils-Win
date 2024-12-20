// The MIT License(MIT)
// Copyright © 2024 Case Technologies

#pragma once
#include "Common.hpp"

namespace CUtils
{
    // Простой класс для управления корутинами
    class Coroutine {
    public:
        // Тип для возврата из корутины
        struct promise_type {
            Coroutine get_return_object() {
                return Coroutine{ Handle::from_promise(*this) };
            }

            std::suspend_always initial_suspend() noexcept { return {}; }
            std::suspend_always final_suspend() noexcept { return {}; }

            void unhandled_exception() {
                std::rethrow_exception(std::current_exception());
            }

            void return_void() noexcept {}
        };

        using Handle = std::coroutine_handle<promise_type>;

        Coroutine() noexcept : handle_(nullptr) {}
        explicit Coroutine(Handle handle) : handle_(handle) {}

        Coroutine(const Coroutine&) = delete;
        Coroutine& operator=(const Coroutine&) = delete;

        Coroutine(Coroutine&& other) noexcept : handle_(other.handle_) {
            other.handle_ = nullptr;
        }

        Coroutine& operator=(Coroutine&& other) noexcept {
            if (this != &other) {
                if (handle_) {
                    handle_.destroy();
                }
                handle_ = other.handle_;
                other.handle_ = nullptr;
            }
            return *this;
        }

        ~Coroutine() {
            if (handle_) {
                handle_.destroy();
            }
        }

        // Возобновление выполнения корутины
        bool resume() {
            if (!handle_.done()) {
                handle_.resume();
            }
            return !handle_.done();
        }

        // Проверка, завершена ли корутина
        bool done() const {
            return handle_.done();
        }

    private:
        Handle handle_;
    };
}
