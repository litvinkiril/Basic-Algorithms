#include "string_algorithms.hpp"

namespace str {
    std::vector<int> prefix_function(const std::string& s) {
        int n = s.size();
        std::vector<int> pi(n, 0);
        for (int i = 1; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) j = pi[j - 1];
            if (s[i] == s[j]) j++;
            pi[i] = j;
        }
        return pi;
    }

    std::vector<int> z_function(const std::string& s) {
        int n = s.size();
        std::vector<int> z(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i <= r) z[i] = std::min(r - i + 1, z[i - l]);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        if (n > 0) z[0] = n;
        return z;
    }

    std::vector<int> kmp_search(const std::string& text, const std::string& pattern) {
        std::string combined = pattern + "#" + text;
        std::vector<int> pi = prefix_function(combined);
        std::vector<int> positions;
        int m = pattern.size();
        for (int i = m + 1; i < combined.size(); i++) {
            if (pi[i] == m) positions.push_back(i - 2 * m);
        }
        return positions;
    }

    long long PalindromeInfo::count() const {
        long long cnt = 0;
        for (int r : odd) cnt += r;
        for (int r : even) cnt += r;
        return cnt;
    }

    bool PalindromeInfo::is_palindrome(int l, int r) const {
        int len = r - l;
        int mid = (l + r) / 2;
        if (len % 2 == 1) return odd[mid] >= (len + 1) / 2;
        else return even[mid] >= len / 2;
    }

    PalindromeInfo manacher(const std::string& s) {
        int n = s.size();
        PalindromeInfo result;
        result.odd.resize(n, 0);
        result.even.resize(n, 0);

        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = (i > r) ? 1 : std::min(result.odd[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
            result.odd[i] = k;
            k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }

        l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = (i > r) ? 0 : std::min(result.even[l + r - i + 1], r - i + 1);
            while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) k++;
            result.even[i] = k;
            if (i + k - 1 > r) {
                l = i - k;
                r = i + k - 1;
            }
        }
        return result;
    }

    std::string longest_common_substring(const std::string& s1, const std::string& s2) {
        int n = s1.size(), m = s2.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
        int max_len = 0, end_pos = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] > max_len) {
                        max_len = dp[i][j];
                        end_pos = i - 1;
                    }
                }
            }
        }
        return max_len > 0 ? s1.substr(end_pos - max_len + 1, max_len) : "";
    }

    int levenshtein_distance(const std::string& a, const std::string& b) {
        int n = a.size(), m = b.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
        for (int i = 0; i <= n; i++) dp[i][0] = i;
        for (int j = 0; j <= m; j++) dp[0][j] = j;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = 1 + std::min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
            }
        }
        return dp[n][m];
    }

    std::vector<int> find_anagrams(const std::string& text, const std::string& pattern) {
        if (pattern.size() > text.size()) return {};
        std::vector<int> result;
        std::vector<int> p_cnt(26, 0), w_cnt(26, 0);
        for (char c : pattern) p_cnt[c - 'a']++;
        for (int i = 0; i < text.size(); i++) {
            w_cnt[text[i] - 'a']++;
            if (i >= pattern.size()) w_cnt[text[i - pattern.size()] - 'a']--;
            if (i >= pattern.size() - 1 && p_cnt == w_cnt)
                result.push_back(i - pattern.size() + 1);
        }
        return result;
    }

    std::vector<int> build_lcp(const std::string& s, const std::vector<int>& sa) {
        int n = s.size();
        std::vector<int> rank(n);
        for (int i = 0; i < n; i++) rank[sa[i]] = i;
        std::vector<int> lcp(n - 1);
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (rank[i] == n - 1) { k = 0; continue; }
            int j = sa[rank[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
            lcp[rank[i]] = k;
            if (k > 0) k--;
        }
        return lcp;
    }
}