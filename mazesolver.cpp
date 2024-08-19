#include <iostream>
#include <vector>

using namespace std;

const int N = 5; // Size of the maze (NxN)

// Directions for moving up, down, left, right
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// The maze
int maze[N][N] = {
    { 1, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 0 },
    { 0, 0, 0, 1, 0 },
    { 1, 1, 0, 1, 1 },
    { 0, 1, 1, 0, 1 }
};

// Solution matrix
int solution[N][N] = { 0 };

// Function to check if the next move is valid
bool isValidMove(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// Depth-First Search function
bool solveMaze(int x, int y) {
    // If the goal is reached
    if (x == N - 1 && y == N - 1) {
        solution[x][y] = 1;
        return true;
    }

    // Check if it's valid to move to (x, y)
    if (isValidMove(x, y)) {
        solution[x][y] = 1; // Mark the current cell as part of the solution path

        // Move in all possible directions
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (solveMaze(newX, newY)) {
                return true;
            }
        }

        solution[x][y] = 0; // Backtrack
    }

    return false;
}

void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    if (solveMaze(0, 0)) {
        cout << "Solution found:\n";
        printSolution();
    } else {
        cout << "No solution exists\n";
    }

    return 0;
}
