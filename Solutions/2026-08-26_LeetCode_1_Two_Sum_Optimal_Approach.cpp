/*
Problem Name   : 1. Two Sum
Platform       : LeetCode
Topic          : Array, Hash Table
Problem Link   : https://leetcode.com/problems/two-sum/submissions/2121260244/
Difficulty     : Easy
Date Solved    : 2026-08-26
Approach       : Optimal Approach
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end() && hash[complement] != i) {
                return {i, hash[complement]};
            }
        }
        // If no valid pair is found, return an empty vector
        return {};
    }
};
