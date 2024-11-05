// The MIT License (MIT)
// Copyright © 2024 Case Technologies

#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <stdexcept>

namespace CUtils
{
    class Hashed
    {
    public:
        void HashAndSave(const std::string& text, const std::string& filename);
        std::string ReadHashFromFile(const std::string& filename) const;

    private:
        std::string sha256(const std::string& str) const;
        unsigned int bswap32(unsigned int value) const;
    };
}