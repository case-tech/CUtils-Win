// The MIT License (MIT)
// Copyright © 2024 Case Technologies

#pragma once
#include "Common.hpp"

namespace CUtils
{
    class Filesystem 
    {
    public:
        Filesystem()  = default;
        ~Filesystem() = default;

        bool CreateDirectory(const std::string& path);
        bool Remove(const std::string& path);
        bool Rename(const std::string& oldPath, const std::string& newPath);
        bool Exists(const std::string& path) const;
        bool Copy(const std::string& from, const std::string& to, bool recursive = false);

        std::vector<std::string> ListDirectory(const std::string& path) const;
        std::string GetAbsolutePath(const std::string& path) const;

        bool IsDirectory(const std::string& path) const;
        bool IsFile(const std::string& path) const;

        uintmax_t FileSize(const std::string& path) const;

    private:
        void CopyDirectoryRecursive(const std::filesystem::path& from, const std::filesystem::path& to);
    };
}
