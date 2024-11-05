// The MIT License (MIT)
// Copyright © 2024 Case Technologies

#pragma once
#include <string>
#include <typeinfo>
#include <typeindex>
#include <unordered_map>
#include <memory>

namespace CUtils
{
    class RTTI
    {
    public:
        virtual ~RTTI() = default;

        virtual std::string GetTypeName() const = 0;

        static void RegisterType(const std::type_index& typeId, const std::string& typeName);
        static std::string GetTypeNameById(const std::type_index& typeId);

    protected:
        RTTI()
        {
            RegisterType(std::type_index(typeid(*this)), GetTypeName());
        }
    };

    #define RTTI_DECLARE_TYPE(type) \
        public: \
            virtual std::string GetTypeName() const override { return #type; }
}
