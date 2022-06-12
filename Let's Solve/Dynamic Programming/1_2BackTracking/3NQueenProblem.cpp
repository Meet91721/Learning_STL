// https://leetcode.com/problems/n-queens/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<string>> res;

    bool isCrossed(int row, int col, vector<string> board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            if (board[row][i] == 'Q')
                return true;
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                if (abs(i - row) == abs(j - col) && board[i][j] == 'Q')
                {
                    return true;
                }
            }
        }
        return false;
    }

    void solver(vector<string> &board, int col)
    {

        if (col == board.size())
        {
            res.push_back(board);
            return;
        }

        for (int i = 0; i < board.size(); i++)
        {
            if (isCrossed(i, col, board))
                continue;
            board[i][col] = 'Q';
            solver(board, col + 1);
            board[i][col] = '.';
        }

        return;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n);
        for (int i = 0; i < n; i++)
        {
            string t;
            for (int j = 0; j < n; j++)
            {
                t += '.';
            }
            board[i] = t;
        }

        solver(board, 0);
        return res;
    }
};