/*
Leetcode 1: Two Sum

** Description **
Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

** Example **
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> exist;
        vector<int> ret { 0, 1 };

        for (int i = 0; i < nums.size(); i++) { 
            int comp = target - nums[i];
            if (exist[comp] != 0) {
                ret[0] = exist[comp] - 1;
                ret[1] = i;
                return ret;
            }
            exist[nums[i]] = i + 1;
        }
    }
};