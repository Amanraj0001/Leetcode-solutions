/*
Problem Name   : 1. Two Sum
Platform       : LeetCode
Topic          : Array, Hash Table
Problem Link   : https://leetcode.com/problems/two-sum/submissions/2121260244/
Difficulty     : Easy
Date Solved    : 2026-08-26
Approach       : Brute Force
Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // No solution found
    }
};
