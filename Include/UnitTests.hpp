// The MIT License (MIT)
// Copyright © 2024 Case Technologies

#pragma once
#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <cstring>
#include <string>

namespace CUtils
{
#define ASSERT_TRUE(condition) \
        if (!(condition))      \
        { std::cerr << "ASSERT_TRUE failed: " #condition << std::endl; return; }

#define ASSERT_FALSE(condition) \
        if (condition)          \
        { std::cerr << "ASSERT_FALSE failed: " #condition << std::endl; return; }

#define ASSERT_EQ(expected, actual) \
        if ((expected) != (actual)) \
        { std::cerr << "ASSERT_EQ failed: " #expected " != " #actual << std::endl; return; }

#define ASSERT_NE(val1, val2) \
        if ((val1) == (val2)) \
        { std::cerr << "ASSERT_NE failed: " #val1 " == " #val2 << std::endl; return; }

#define ASSERT_LT(val1, val2)   \
        if (!((val1) < (val2))) \
        { std::cerr << "ASSERT_LT failed: " #val1 " >= " #val2 << std::endl; return; }

#define ASSERT_LE(val1, val2)    \
        if (!((val1) <= (val2))) \
        { std::cerr << "ASSERT_LE failed: " #val1 " > " #val2 << std::endl; return; }

#define ASSERT_GT(val1, val2)   \
        if (!((val1) > (val2))) \
        { std::cerr << "ASSERT_GT failed: " #val1 " <= " #val2 << std::endl; return; }

#define ASSERT_GE(val1, val2)    \
        if (!((val1) >= (val2))) \
        { std::cerr << "ASSERT_GE failed: " #val1 " < " #val2 << std::endl; return; }

#define ASSERT_STREQ(expected_str, actual_str)              \
        if (std::strcmp((expected_str), (actual_str)) != 0) \
        { std::cerr << "ASSERT_STREQ failed: " #expected_str " != " #actual_str << std::endl; return; }

#define ASSERT_STRNE(str1, str2)              \
        if (std::strcmp((str1), (str2)) == 0) \
        { std::cerr << "ASSERT_STRNE failed: " #str1 " == " #str2 << std::endl; return; }

#define ASSERT_STRCASEEQ(expected_str, actual_str)       \
        if (_stricmp((expected_str), (actual_str)) != 0) \
        { std::cerr << "ASSERT_STRCASEEQ failed: " #expected_str " != " #actual_str << std::endl; return; }

#define ASSERT_STRCASENE(str1, str2)       \
        if (_stricmp((str1), (str2)) == 0) \
        { std::cerr << "ASSERT_STRCASENE failed: " #str1 " == " #str2 << std::endl; return; }

#define EXPECT_TRUE(condition)  if (!(condition)) { std::cerr << "EXPECT_TRUE failed: " #condition << std::endl; }
#define EXPECT_FALSE(condition) if (condition) { std::cerr << "EXPECT_FALSE failed: " #condition << std::endl; }

#define ASSERT_THROW(statement, exception_type) \
    try { statement; std::cerr << "ASSERT_THROW failed: Expected exception " #exception_type << std::endl; return; } \
    catch (const exception_type&) {}

#define ASSERT_NO_THROW(statement) \
    try { statement; } \
    catch (...) { std::cerr << "ASSERT_NO_THROW failed: Unexpected exception thrown" << std::endl; return; }

#define SUCCEED() (std::cout << "Test succeeded" << std::endl)
#define FAIL()    (std::cerr << "Test failed" << std::endl; return)

#define UTEST(test_case_name, test_name) \
    void test_case_name##_##test_name(); \
    struct test_case_name##_##test_name##_registrar { \
        test_case_name##_##test_name##_registrar() { \
            tests.emplace_back(#test_case_name, #test_name, test_case_name##_##test_name); \
        } \
    } test_case_name##_##test_name##_instance; \
    void test_case_name##_##test_name()

    struct Test 
    {
        std::string test_case_name;
        std::string test_name;
        std::function<void()> func;

        Test(const std::string& case_name, const std::string& name, const std::function<void()>& f)
            : test_case_name(case_name), test_name(name), func(f) {}
    };

    static std::vector<Test> registry;

    inline int RUN_ALL_TESTS() 
    {
        int passed = 0;
        int failed = 0;
        for (auto& test : registry) 
        {
            std::cout << "Running test " << test.test_case_name << "." << test.test_name << std::endl;
            try 
            {
                test.func();
                std::cout << "[  PASSED  ] " << test.test_case_name << "." << test.test_name << std::endl;
                passed++;
            }
            catch (...) 
            {
                std::cerr << "[  FAILED  ] " << test.test_case_name << "." << test.test_name << std::endl;
                failed++;
            }
        }
        std::cout << "Tests passed: " << passed << ", Tests failed: " << failed << std::endl;
        return failed > 0 ? 1 : 0;
    }

}
