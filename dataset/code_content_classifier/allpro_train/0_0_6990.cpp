#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<char>> board(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    long long sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] != '#' && board[i][j] != '0') {
                for (int k = i + 1; k < N; k++) {
                    if (board[k][j] != '#' && board[k][j] != '0') {
                        sum += (board[i][j] - '0') * (board[k][j] - '0');
                    } else {
                        break;
                    }
                }
                for (int k = j + 1; k < N; k++) {
                    if (board[i][k] != '#' && board[i][k] != '0') {
                        sum += (board[i][j] - '0') * (board[i][k] - '0');
                    } else {
                        break;
                    }
                }
            }
        }
    }

    cout << sum << endl;

    return 0;
}