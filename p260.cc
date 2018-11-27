/*
Leetcode 260: Single Number III

** Description **
Given an array of numbers nums, in which exactly two elements appear only once
and all the other elements appear exactly twice. Find the two elements that
appear only once.

** Example **
Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

** Note **
[1] The order of the result is not important. So in the above example, [5, 3] is
also correct.
[2] Your algorithm should run in linear runtime complexity. Could
you implement it using only constant space complexity?
*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    vector<int> ret{0, 0};
    int xor_res = 0;

    for (int i = 0; i < nums.size(); i++) {
      xor_res ^= nums[i];
    }

    int bit_flag = xor_res & (~(xor_res - 1));

    for (int i = 0; i < nums.size(); i++) {
      if (bit_flag & nums[i]) {
        ret[0] ^= nums[i];
      } else {
        ret[1] ^= nums[i];
      }
    }

    return ret;
  }
};

int main() {
  Solution sol;
  vector<int> v{0, 0, 1, 2};
  auto r = sol.singleNumber(v);
  cout << r[0] << ", " << r[1] << endl;
}
