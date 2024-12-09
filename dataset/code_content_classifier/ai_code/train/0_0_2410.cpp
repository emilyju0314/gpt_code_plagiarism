#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> board(N);
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    int count = 0;
    for (int A = 0; A < N; A++) {
        for (int B = 0; B < N; B++) {
            bool isGoodBoard = true;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (board[i][j] != board[(i+A)%N][(j+B)%N] || board[i][j] != board[(j+B)%N][(i+A)%N]) {
                        isGoodBoard = false;
                        break;
                    }
                }
                if (!isGoodBoard) break;
            }
            if (isGoodBoard) count++;
        }
    }

    cout << count << endl;

    return 0;
}