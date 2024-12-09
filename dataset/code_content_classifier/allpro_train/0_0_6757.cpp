#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int knight_moves(int from, int to, int N) {
    int from_x = (from - 1) % N + 1;
    int from_y = (from - 1) / N + 1;
    int to_x = (to - 1) % N + 1;
    int to_y = (to - 1) / N + 1;

    int dx = abs(from_x - to_x);
    int dy = abs(from_y - to_y);

    if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1)) {
        return 1;
    } else {
        return 2;
    }
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> chessboard(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> chessboard[i][j];
        }
    }

    int curr_square = 1;
    int steps = 0, replacements = 0;

    for (int i = 2; i <= N*N; i++) {
        int next_square = i;
        int min_steps = INT_MAX;
        int min_replacements = INT_MAX;

        for (int piece = 1; piece <= 3; piece++) {
            int piece_steps = knight_moves(curr_square, next_square, N);

            if (piece != 1) {
                piece_steps++;
            }

            if (steps + piece_steps < min_steps) {
                min_steps = steps + piece_steps;
                min_replacements = replacements + (piece != 1);
            }
        }

        steps = min_steps;
        replacements = min_replacements;
        curr_square = next_square;
    }

    cout << steps << " " << replacements << endl;

    return 0;
}