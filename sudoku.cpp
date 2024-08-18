#include <iostream>
#include <vector>

using namespace std;

// Function to print the Sudoku grid
void printGrid(vector<vector<int>>& grid) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Function to check if it's safe to place a number in the given position
bool isSafe(vector<vector<int>>& grid, int row, int col, int num) {
    // Check the row
    for (int x = 0; x < 9; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    // Check the column
    for (int x = 0; x < 9; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    // Check the 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku using backtracking
bool solveSudoku(vector<vector<int>>& grid, int row, int col) {
    // If we have reached the last cell, the Sudoku is solved
    if (row == 8 && col == 9) {
        return true;
    }

    // Move to the next row if we reached the end of the current row
    if (col == 9) {
        row++;
        col = 0;
    }

    // Skip the cells that are already filled
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col + 1);
    }

    // Try placing numbers from 1 to 9 in the current cell
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            // Recur to place the next number
            if (solveSudoku(grid, row, col + 1)) {
                return true;
            }

            // Backtrack if placing the current number doesn't lead to a solution
            grid[row][col] = 0;
        }
    }

    return false;  // Trigger backtracking
}

int main() {
    // Define a 9x9 Sudoku grid with some pre-filled values (0 represents an empty cell)
    vector<vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(grid, 0, 0)) {
        printGrid(grid);
    } else {
        cout << "No solution exists!" << endl;
    }

    return 0;
}
