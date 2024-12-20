// The MIT License(MIT)
// Copyright © 2024 Case Technologies

#pragma once

// C++ libraries
#include <coroutine>
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <map>

#ifdef _WIN32 || _WIN64
#include <windows.h> 
#else
#include <dlfcn.h>  
#endif

#include <future>
#include <random>
#include <typeindex>
#include <vector>
#include <iomanip>
#include <cstring>
#include <variant>
#include <thread>
#include <mutex>