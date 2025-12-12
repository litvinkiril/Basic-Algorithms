#include "string_algorithms.hpp"
#include <cassert>
#include <iostream>

void test_prefix() {
    std::cout << "Testing prefix_function... ";
    auto p = str::prefix_function("abcabcd");
    std::vector<int> expected1 = { 0,0,0,1,2,3,0 };
    assert(p == expected1);

    p = str::prefix_function("aaaaa");
    std::vector<int> expected2 = { 0,1,2,3,4 };
    assert(p == expected2);

    p = str::prefix_function("ababab");
    std::vector<int> expected3 = { 0,0,1,2,3,4 };
    assert(p == expected3);
    std::cout << "OK\n";
}

void test_z() {
    std::cout << "Testing z_function... ";
    auto z = str::z_function("abacaba");
    std::vector<int> expected1 = { 7,0,1,0,3,0,1 };
    assert(z == expected1);

    z = str::z_function("aaaaa");
    std::vector<int> expected2 = { 5,4,3,2,1 };
    assert(z == expected2);

    z = str::z_function("abcde");
    std::vector<int> expected3 = { 5,0,0,0,0 };
    assert(z == expected3);
    std::cout << "OK\n";
}

void test_kmp() {
    std::cout << "Testing kmp_search... ";
    auto pos = str::kmp_search("abacaba", "aba");
    std::vector<int> expected1 = { 0,4 };
    assert(pos == expected1);

    pos = str::kmp_search("abcdef", "xyz");
    assert(pos.empty());

    pos = str::kmp_search("aaaaa", "aa");
    std::vector<int> expected2 = { 0,1,2,3 };
    assert(pos == expected2);
    std::cout << "OK\n";
}

void test_manacher() {
    std::cout << "Testing manacher... ";
    auto res = str::manacher("aba");
    assert(res.count() == 4);
    assert(res.is_palindrome(0, 3));
    assert(!res.is_palindrome(0, 2));

    res = str::manacher("abba");
    assert(res.is_palindrome(0, 4));
    assert(res.is_palindrome(1, 3));

    res = str::manacher("abc");
    assert(res.count() == 3);
    assert(!res.is_palindrome(0, 3));
    std::cout << "OK\n";
}

void test_lcs() {
    std::cout << "Testing longest_common_substring... ";
    auto lcs = str::longest_common_substring("abacaba", "baca");
    assert(lcs == "baca");

    lcs = str::longest_common_substring("abc", "def");
    assert(lcs.empty());

    lcs = str::longest_common_substring("abcdef", "cdefgh");
    assert(lcs == "cdef");
    std::cout << "OK\n";
}

void test_levenshtein() {
    std::cout << "Testing levenshtein_distance... ";
    int d = str::levenshtein_distance("kitten", "sitting");
    assert(d == 3);

    d = str::levenshtein_distance("abc", "abc");
    assert(d == 0);

    d = str::levenshtein_distance("", "abc");
    assert(d == 3);

    d = str::levenshtein_distance("abc", "");
    assert(d == 3);
    std::cout << "OK\n";
}

void test_anagrams() {
    std::cout << "Testing find_anagrams... ";
    auto pos = str::find_anagrams("cbaebabacd", "abc");
    std::vector<int> expected1 = { 0,6 };
    assert(pos == expected1);

    pos = str::find_anagrams("abab", "ab");
    std::vector<int> expected2 = { 0,1,2 };
    assert(pos == expected2);

    pos = str::find_anagrams("abc", "abcd");
    assert(pos.empty());
    std::cout << "OK\n";
}

/*
int main() {
    try {
        std::cout << "Running tests...\n\n";

        test_prefix();
        test_z();
        test_kmp();
        test_manacher();
        test_lcs();
        test_levenshtein();
        test_anagrams();

        std::cout << "\nAll tests passed successfully!\n";
        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "\nERROR: " << e.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "\nERROR: Unknown error occurred" << std::endl;
        return 1;
    }
}*/