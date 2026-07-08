class Solution {
private:
    vector<vector<string>> result;  // stores all palindrome partitions
    vector<string> path;            // current path of substrings

    // Helper function to check if s[l..r] is a palindrome
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    // DFS function to explore all partitions starting from 'start'
    void dfs(string &s, int start) {
        // Base case: reached the end of string
        if (start == s.size()) {
            result.push_back(path);  // save the current valid partition
            return;
        }

        // Try all possible substrings starting from 'start'
        for (int end = start; end < s.size(); end++) {
            // Check if the substring s[start..end] is a palindrome
            if (isPalindrome(s, start, end)) {
                // Choose: add the palindrome substring to current path
                path.push_back(s.substr(start, end - start + 1));

                // Explore: recursively find partitions for the remaining string
                dfs(s, end + 1);

                // Backtrack: remove the last substring and try next possibility
                path.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);  // start DFS from index 0
        return result;
    }
};
