// Copyright [2016] <Huang Jiaming>
class Solution {
    /*
     * one-pass solution with an index reference.
     * 3[a2[c]] -> accaccacc
     *
     */
  public:
    string decodeString(string s, int& i) {
        string ret;

        while (i < s.size() && s[i] != ']') {
            if (!isdigit(s[i]))
                ret += s[i++];
            else {
                int n = 0;
                while (i < s.size() && isdigit(s[i]))
                    n = n * 10 + s[i++] - '0';

                i++;  // skip '['
                string p = decodeString(s, i);
                i++;  // skip ']'

                while (n > 0) {
                    ret += p;
                    n--;
                }
            }
        }

        return ret;
    }

    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
};
