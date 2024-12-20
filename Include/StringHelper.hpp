// The MIT License (MIT)
// Copyright © 2024 Case Technologies

#pragma once
#include "Common.hpp"

namespace CUtils
{
   class StringHelper 
   {
   public:
      StringHelper() = default;
      StringHelper(const std::string& str);
      StringHelper(const char* str);

      std::string ToLowerCase() const;
      std::string ToUpperCase() const;
      std::string Trim() const;
      std::vector<std::string> Split(char delimiter) const;
      bool Contains(const std::string& substr) const;
      bool StartsWith(const std::string& prefix) const;
      bool EndsWith(const std::string& suffix) const;
      std::string Replace(const std::string& oldStr, const std::string& newStr) const;
      int IndexOf(const std::string& substr) const;
      int LastIndexOf(const std::string& substr) const;
      std::string Substring(size_t start, size_t length = std::string::npos) const;
      bool IsEmpty() const;
      size_t Length() const;
      std::string ExtractNumericPart() const;

      StringHelper& operator=(const std::string& str);
      StringHelper& operator=(const char* str);
      bool operator==(const StringHelper& other) const;
      bool operator!=(const StringHelper& other) const;

      std::optional<int> ToInt() const;
      std::optional<double> ToDouble() const;
      std::optional<bool> ToBool() const;

      operator std::string() const;

   private:
      std::string data;
   };
}
