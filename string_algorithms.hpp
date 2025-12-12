#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

namespace str {
    std::vector<int> prefix_function(const std::string& s);
    std::vector<int> z_function(const std::string& s);
    std::vector<int> kmp_search(const std::string& text, const std::string& pattern);

    struct PalindromeInfo {
        std::vector<int> odd, even;
        long long count() const;
        bool is_palindrome(int l, int r) const;
    };

    PalindromeInfo manacher(const std::string& s);
    std::string longest_common_substring(const std::string& s1, const std::string& s2);
    int levenshtein_distance(const std::string& a, const std::string& b);
    std::vector<int> find_anagrams(const std::string& text, const std::string& pattern);
    std::vector<int> build_lcp(const std::string& s, const std::vector<int>& sa);
}