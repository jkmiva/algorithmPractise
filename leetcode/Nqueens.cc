// Copyright [2016] <Huang Jiaming>
#include <vector>
#include <string>
class solutino {
  public:
    std::vector<std::vector<std::string> > solveNQueens(int n) {
        std::vector<std::vector<std::string> > res;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        solveNQueens(res, nQueens, 0, n);
        return res;
    }
  private:
    void solveNQueens(std::vector<std::vector<std::string> >& res,
                      std::vector<std::string>& nQueens,
                      int row,
                      int& n) {
        if (row == n) {
            res.push_back(nQueens);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                solveNQueens(res, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
        }
    }
    bool isValid(std::vector<std::string>& nQueens, int row, int col, int n) {
        for (int i = 0; i != row; i++) {
            if (nQueens[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (nQueens[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n;  i--, j++) {
            if (nQueens[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};
