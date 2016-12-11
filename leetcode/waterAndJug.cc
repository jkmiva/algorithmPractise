// Copyright [2016] <Huang Jiaming>
/*
 * pure math problem, if
 * z % gcd(x,y) == 0, return true; else return false
 */
class Solution {
  public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false;
        if (x == z || y == z || x+y == z) return true;
        int gcd = mygcd(x,y);
        return z%gcd==0;
    }

    int mygcd(int x, int y) {
        if (x < y) {
            return mygcd(y,x);
        }
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }
};
