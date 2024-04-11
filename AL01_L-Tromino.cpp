#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;

int trominoNumber = 1;

void placeTromino(vector<vector<int>>& board, int x, int y) {
    if (board[x][y] == 0) {
        board[x][y] = trominoNumber;
    }
}

void tile(vector<vector<int>>& board, int size, pair<int, int> tar) {
    if (size == 2) {
        trominoNumber++;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                placeTromino(board, tar.X + i, tar.Y + j);
            }
        }
    } else {
        int half = size / 2;
        pair<int, int> center = {tar.X + half - 1, tar.Y + half - 1};

        trominoNumber++;
        placeTromino(board, center.X, center.Y);
        placeTromino(board, center.X, center.Y + 1);
        placeTromino(board, center.X + 1, center.Y);

        tile(board, half, {tar.X, tar.Y}); // Top-left
        tile(board, half, {tar.X, tar.Y + half}); // Top-right
        tile(board, half, {tar.X + half, tar.Y}); // Bottom-left
        tile(board, half, {center.X + 1, center.Y + 1}); // Bottom-right
    }
}

int main() {
    int size = 8;
    pair<int, int> forbidden = {1, 1};

    vector<vector<int>> board(size, vector<int>(size, 0));
    board[forbidden.X][forbidden.Y] = -1;

    tile(board, size, {0, 0});

    for (const auto& row : board) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}