#include <vector>

class Solution {
public:
    /**
     * @brief Solves the Sudoku puzzle using a backtracking algorithm.
     * @param board The 9x9 Sudoku board represented as a vector of vectors of characters.
     * Empty cells are denoted by '.'.
     * @return True if a solution is found, otherwise false. The board is modified in-place.
     */
    bool solveSudoku(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // Find an empty cell
                if (board[i][j] == '.') {
                    // Try placing numbers '1' through '9'
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c; // Place the number

                            // Recursively try to solve the rest of the board
                            if (solveSudoku(board)) {
                                return true; // Solution found
                            } else {
                                board[i][j] = '.'; // Backtrack if the placement was wrong
                            }
                        }
                    }
                    // If no number '1'-'9' works in this cell, trigger backtracking
                    return false;
                }
            }
        }
        // If all cells are filled, the puzzle is solved
        return true;
    }

    /**
     * @brief Checks if placing a character 'c' at a given (row, col) is valid.
     * @param board The Sudoku board.
     * @param row The row index.
     * @param col The column index.
     * @param c The character to validate.
     * @return True if the move is valid, otherwise false.
     */
    bool isValid(std::vector<std::vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check if 'c' is already in the current row
            if (board[row][i] == c) {
                return false;
            }

            // Check if 'c' is already in the current column
            if (board[i][col] == c) {
                return false;
            }

            // Check if 'c' is already in the current 3x3 sub-box
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
                return false;
            }
        }
        return true;
    }
};