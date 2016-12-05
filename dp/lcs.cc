// Copyright [2016] <Huang Jiaming>
/**
 * longest common subsequence
 * given two string X, Y whose length are m and n respectively
 * if X_m == Y_n, lcs(m,n) = 1 + lcs(m-1,n-1)
 * if X_m != Y_n, lcs(m,n) = max(lcs(m-1,n), lcs(m,n-1))
 */

#include <iostream>
#include <cstring>

class Lcs {
public:
    static int lcs(char x[], char y[], int m, int n) {
        int lcs[m+1][n+1];

        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    lcs[i][j] = 0;  // initialize
                }
                else if (x[i-1] == y[j-1]) {
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                }
                else {
                    lcs[i][j] = lcs[i-1][j] > lcs[i][j-1] ? lcs[i-1][j] : lcs[i][j-1];
                }
            }
        }
        return lcs[m][n];
    }
};

int main(int argc, char *argv[])
{
    char x[] = "AGGTAB";
    char y[] = "GXTXAYB";
    int m = strlen(x);
    int n = strlen(y);
    std::cout << "get " << Lcs::lcs(x, y, m, n) << ", expected 4." << std::endl;

    return 0;
}
