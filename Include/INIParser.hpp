// The MIT License (MIT)
// Copyright © 2024 Case Technologies

#pragma once
#include "Common.hpp"

namespace CUtils
{
    class INIParser
    {
    public:
        INIParser(const std::string& filename);
        bool Load();
        bool Save() const;

        std::string GetValue(const std::string& section, const std::string& key) const;
        void SetValue(const std::string& section, const std::string& key, const std::string& value);
        std::vector<std::string> GetSections() const;
        std::map<std::string, std::string> GetKeys(const std::string& section) const;

    private:
        std::string filename_;
        std::map<std::string, std::map<std::string, std::string>> data_;

        void Trim(std::string& str) const;
    };
}