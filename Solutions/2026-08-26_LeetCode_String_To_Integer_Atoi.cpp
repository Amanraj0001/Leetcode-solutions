/*
Problem Name   : String To Integer Atoi
Platform       : LeetCode
Topic          : General
Problem Link   : https://leetcode.com/problems/string-to-integer-atoi/submissions/2121266434/
Difficulty     : Easy
Date Solved    : 2026-08-26
*/

if (isdigit(c)) {
            started = true;
            int digit = c - '0';

            if (num > INT_MAX / 10 ||
               (num == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            return helper(s, i + 1, num, sign, true);
        }

        }
            return helper(s, i + 1, num, sign, true);
            sign = (c == '-') ? -1 : 1;
        if (!started && (c == '+' || c == '-')) {

        }
            return helper(s, i + 1, num, sign, false);
        if (!started && c == ' ') {

        char c = s[i];
