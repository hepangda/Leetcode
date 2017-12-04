/*
Leetcode 3: Longest Substring Without Repeating Characters

** Description **
Given a string, find the length of the longest substring without repeating characters.

** Examples **
Given "abcabcbb", the answer is "abc", which the length is 3.
Given "bbbbb", the answer is "b", with the length of 1.
Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool charset[256] = { 0 };
        int now_size = 0, max_size = 0;

        for (string::size_type i = 0, j = 0; i < s.size(); i++) {
            if (charset[s[i]]) {
                charset[s[j++]] = false;
                max_size = (now_size > max_size) ? now_size : max_size;
                --now_size, --i;
            } else {
                charset[s[i]] = true;
                ++now_size;
            }
        }
        max_size = (now_size > max_size) ? now_size : max_size;

        return max_size;
    }
};