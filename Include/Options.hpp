// The MIT License (MIT)
// Copyright © 2024 Case Technologies

#pragma once
#include <string>
#include <map>
#include <vector>
#include <iostream>

namespace CUtils
{
    class Options
    {
    public:
        Options(int argc, char* argv[]);

        void AddOption(const std::string& option, const std::string& description);
        bool IsOptionSet(const std::string& option) const;
        std::string GetOptionValue(const std::string& option) const;
        void PrintHelp() const;

    private:
        std::map<std::string, std::string> options_;
        std::vector<std::string> args_;
    };
}