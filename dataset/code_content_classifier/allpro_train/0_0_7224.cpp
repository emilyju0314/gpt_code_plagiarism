#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> chessboard(n);
    for (int i = 0; i < n; i++) {
        cin >> chessboard[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (chessboard[i][j] == '.') {
                if ((i + j) % 2 == 0) {
                    cout << "B";
                } else {
                    cout << "W";
                }
            } else {
                cout << "-";
            }
        }
        cout << endl;
    }

    return 0;
}