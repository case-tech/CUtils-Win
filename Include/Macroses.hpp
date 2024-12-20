// The MIT License(MIT)
// Copyright © 2024 Case Technologies

#pragma once

// For Compilers
#if defined(_MSC_VER)
    // Microsoft Visual C++ (MSVC)
#define COMPILER_MSVC 1
#define COMPILER_NAME "MSVC"
#elif defined(__GNUC__)
    // GCC or Clang
#define COMPILER_GCC 1
#define COMPILER_NAME "GCC"
#elif defined(__clang__)
    // Clang
#define COMPILER_CLANG 1
#define COMPILER_NAME "Clang"
#elif defined(__INTEL_COMPILER)
    // Intel Compiler
#define COMPILER_INTEL 1
#define COMPILER_NAME "Intel"
#else
    // Other Compilers
#define COMPILER_UNKNOWN 1
#define COMPILER_NAME "Unknown"
#endif

// For Platforms
#if defined(_WIN32) || defined(_WIN64)
    // Windows
#define PLATFORM_WINDOWS 1
#define PLATFORM_NAME "Windows"
#elif defined(__APPLE__) || defined(__MACH__)
    // macOS
#define PLATFORM_MAC 1
#define PLATFORM_NAME "macOS"
#elif defined(__linux__)
    // Linux
#define PLATFORM_LINUX 1
#define PLATFORM_NAME "Linux"
#elif defined(__unix__)
    // Unix
#define PLATFORM_UNIX 1
#define PLATFORM_NAME "Unix"
#else
    // Other Platforms
#define PLATFORM_UNKNOWN 1
#define PLATFORM_NAME "Unknown"
#endif

// Macros for conditional compilation
#if defined(_MSC_VER)
#define FORCE_INLINE __forceinline
#elif defined(__clang__) || defined(__GNUC__)
#define FORCE_INLINE __attribute__((always_inline)) inline
#else
#define FORCE_INLINE inline
#endif

// For Optimization
#define ALIGNAS(x) alignas(x)

// Macros for disabling warnings
#if defined(_MSC_VER)
    // MSVC
#define DISABLE_WARNINGS(warning) __pragma(warning(push)) __pragma(warning(disable : warning))
#define ENABLE_WARNINGS __pragma(warning(pop))
#elif defined(__GNUC__) || defined(__clang__)
    // GCC/Clang
#define DISABLE_WARNINGS(warning) _Pragma("GCC diagnostic push") _Pragma("GCC diagnostic ignored \"#warning\"")
#define ENABLE_WARNINGS _Pragma("GCC diagnostic pop")
#else
#define DISABLE_WARNINGS(warning)
#define ENABLE_WARNINGS
#endif

// Macros for Errors
#define ASSERT(cond) \
    if (!(cond)) { std::cerr << "Assertion failed: " << #cond << std::endl; std::abort(); }

// Macros for measuring arrays
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

// For merge tokens
#define CONCATENATE(a, b) a ## b
#define TO_STRING(x) #x