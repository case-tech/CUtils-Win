// The License (MIT)
// Copyright © 2024 Case Technologies

#pragma once
#include "Common.hpp"

namespace CUtils
{
    class Fusion
    {
    public:
        template <typename... Types>
        using Tuple = std::tuple<Types...>;

        template <typename... Types1, typename... Types2>
        static auto Merge(const Tuple<Types1...>& t1, const Tuple<Types2...>& t2)
        {
            return std::tuple_cat(t1, t2);
        }

        template <std::size_t Index, typename... Types>
        static decltype(auto) Get(const Tuple<Types...>& t)
        {
            return std::get<Index>(t);
        }

        template <typename T, typename... Types>
        static decltype(auto) GetByType(const Tuple<Types...>& t)
        {
            return std::get<T>(t);
        }

        template <typename... Types>
        static auto GetByIndex(const Tuple<Types...>& t, std::size_t index)
        {
            auto accessor = [&]<std::size_t... I>(std::index_sequence<I...>) -> std::variant<Types...>
            {
                std::variant<Types...> result;
                ((index == I ? (result = std::get<I>(t), true) : false), ...);
                if (result.index() == std::variant_npos)
                {
                    throw std::out_of_range("Index out of range");
                }
                return result;
            };

            return accessor(std::index_sequence_for<Types...>{});
        }

        template <typename... Types>
        static constexpr std::size_t Size(const Tuple<Types...>&)
        {
            return sizeof...(Types);
        }

        template <typename... Types1, typename... Types2>
        static bool AreEqual(const Tuple<Types1...>& t1, const Tuple<Types2...>& t2)
        {
            if constexpr (sizeof...(Types1) != sizeof...(Types2))
            {
                return false;
            }
            else
            {
                return t1 == t2;
            }
        }

        template <typename TupleType, std::size_t... Indices>
        static void PrintHelper(const TupleType& t, std::index_sequence<Indices...>)
        {
            ((std::cout << (Indices == 0 ? "" : ", ") << std::get<Indices>(t)), ...);
        }

        template <typename... Types>
        static void Print(const Tuple<Types...>& t)
        {
            std::cout << "(";
            PrintHelper(t, std::index_sequence_for<Types...>{});
            std::cout << ")" << std::endl;
        }
    };
}
