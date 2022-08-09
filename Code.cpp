#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool check(int i, int j, vector<vector<int>>& sudoku, int ip)    // to check whether sudoku is safe or not on putting a number
{
    for(int k = 0; k < sudoku.size(); k++)
    {
        if(sudoku[i][k] == ip)                      // checking rows
        return false;
        if(sudoku[k][j] == ip)                      // checking columns
        return false;
        if(sudoku[3 * (i/3) + i/3][3 * (j/3) + j%3] == ip)    // checking 3X3 sub matrix
        return false;
    }
    return true;
}
bool SudokuSolver(vector<vector<int>>& sudoku)             
{
    for(int i = 0; i < sudoku[0].size(); i++)
    {
        for(int j = 0; j < sudoku[0].size(); j++)
        {
            if(sudoku[i][j] == 0)                    // to check whether cell is empty and if empty we test the sudoku by putting values recursively
            {
                for(int ip = 1; ip <= 9; ip++)
                {
                    if(check(i, j, sudoku, ip))          // if check passes we proceed
                    {
                        sudoku[i][j] = ip;
                        bool next = SudokuSolver(sudoku);
                        if(next)
                        return true;
                        else
                        sudoku[i][j] = 0;             // if check fails we BACKTRACK
                    }
                }
                return false;
            }
        }
    }
    for(int i = 0; i<sudoku.size(); i++)             // PRINTING THE SOLVED SUDOKU
    {
        for(int j = 0; j < sudoku[i].size(); j++)
        {
            cout << sudoku[i][j]  << " ";
        }
        cout << '\n' ;
    }
    return true;
}
int main()
{
    vector<vector<int>> sudoku;
    for(int i = 0; i<9; i++)
    {
        vector<int> v1;
        for(int j = 0; j < 9; j++)
        {
            int temp;
            cin >> temp ;
            v1.push_back(temp);
        }
        sudoku.push_back(v1);
    }
    cout << "\n#####################\n" << '\n';
    SudokuSolver(sudoku) ;
    return 0;
}
