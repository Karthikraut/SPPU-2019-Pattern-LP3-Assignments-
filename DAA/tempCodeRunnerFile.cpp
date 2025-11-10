#include <iostream>
#include <vector>
using namespace std;

// Function to print the N-Queen solution matrix
void printBoard(const vector<vector<int>>& board, int n) {
    cout << "\nFinal N-Queens Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

// Function to check if a queen can be placed at board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    int i, j;

    // Check column above
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper-left diagonal
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper-right diagonal
    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve N-Queens using Backtracking
bool solveNQueens(vector<vector<int>>& board, int row, int n) {
    // Base case: if all queens are placed
    if (row >= n)
        return true;

    // Try placing the queen in each column of the current row
    for (int col = 0; col < n; col++) {
        if (board[row][col] == 1) {
            // Skip if queen already placed (first queen)
            if (solveNQueens(board, row + 1, n))
                return true;
            else
                return false;
        }

        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;

            // Recurse for next row
            if (solveNQueens(board, row + 1, n))
                return true;

            // Backtrack if placing queen here doesn't lead to a solution
            board[row][col] = 0;
        }
    }

    // If no column works, return false
    return false;
}

int main() {
    int n;
    cout << "Enter the size of the chessboard (N): ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    int r, c;
    cout << "Enter the position of the first Queen (row and column index starting from 0): ";
    cin >> r >> c;

    // Place the first queen
    board[r][c] = 1;

    // Start solving from next row
    if (solveNQueens(board, 0, n))
        printBoard(board, n);
    else
        cout << "No solution exists for this configuration.\n";

    return 0;
}
