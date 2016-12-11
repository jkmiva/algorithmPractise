// Copyright [2016] <Huang Jiaming>
/*
 * 241. Different Ways to Add Parentheses
 */

class Solution {
    /* recursive solution
     * Optimization: we can create a memorization map<string, vector<int>>
     * to memorize sub-result.
     */
 public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
        auto sz = input.size();
        for (int i = 0; i < sz; i++) {
            char op = input[i];
            if (op == '+' || op == '-' || op == '*') {
                vector<int> left  = diffWaysToCompute(input. substr(0, i));
                vector<int> right = diffWaysToCompute(input. substr(i+1));

                for (auto i : left) {
                    for (auto j : right) {
                        if (op == '+') {
                            ret.push_back(i + j);
                        } else if (op == '-') {
                            ret.push_back(i - j);
                        } else {
                            ret.push_back(i * j);
                        }
                    }
                }
            }
        }
        if (ret.empty()) {
            ret.push_back(atoi(input.c_str()));
        }
        return ret;
    }
};
