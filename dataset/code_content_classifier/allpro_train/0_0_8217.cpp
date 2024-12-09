#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int P, M;
vector<vector<vector<int>>> cards;
vector<int> dx = {1, 0, 1, 1}; // for diagonals
vector<int> dy = {0, 1, 1, -1}; // for diagonals

bool checkBingo(vector<vector<int>>& card) {
    // Check rows
    for (int i = 0; i < M; i++) {
        bool bingo = true;
        for (int j = 0; j < M; j++) {
            if (card[i][j] == 0) {
                bingo = false;
                break;
            }
        }
        if (bingo) return true;
    }

    // Check columns
    for (int j = 0; j < M; j++) {
        bool bingo = true;
        for (int i = 0; i < M; i++) {
            if (card[i][j] == 0) {
                bingo = false;
                break;
            }
        }
        if (bingo) return true;
    }

    // Check diagonals
    for (int i = 0; i < M; i++) {
        bool bingo1 = true, bingo2 = true;
        for (int j = 0; j < M; j++) {
            if (card[i][j] == 0) bingo1 = false;
            if (card[j][i] == 0) bingo2 = false;
        }
        if (bingo1 || bingo2) return true;
    }

    // No Bingo
    return false;
}

int minSequence(int player, int current, vector<vector<vector<int>>>& marks) {
    if (player == P) return current;

    int minLen = 9999;

    for (int num = 1; num <= 99; num++) {
        bool found = false;
        for (int k = 0; k < P; k++) {
            if (k < player && checkBingo(marks[k])) {
                found = true;
                break;
            }
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < M; j++) {
                    if (cards[player][i][j] == num) marks[k][i][j] = 1;
                }
            }
        }

        if (found) break;

        int len = minSequence(player + 1, current + 1, marks);
        minLen = min(minLen, len);

        for (int k = 0; k < P; k++) {
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < M; j++) {
                    if (cards[player][i][j] == num) marks[k][i][j] = 0;
                }
            }
        }
    }

    return minLen;
}

int main() {
    while (1) {
        cin >> P >> M;
        if (P == 0 && M == 0) break;

        cards.clear();
        cards.resize(P, vector<vector<int>>(M, vector<int>(M)));
        for (int k = 0; k < P; k++) {
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < M; j++) {
                    cin >> cards[k][i][j];
                }
            }
        }

        vector<vector<vector<int>> > marks(P, vector<vector<int>>(M, vector<int>(M)));
        int result = minSequence(0, 0, marks);

        cout << result << endl;
    }

    return 0;
}