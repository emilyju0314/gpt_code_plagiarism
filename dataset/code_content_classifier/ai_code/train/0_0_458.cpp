#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> square(3, vector<int>(3, 0));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> square[i][j];
        }
    }

    int sum = square[0][1] + square[0][2] + square[1][0] + square[1][2] + square[2][0] + square[2][1];
    int x = (sum - square[1][0] - square[2][2]) / 2;
    square[0][0] = x;
    square[1][1] = (sum - square[0][1] - square[2][1]);
    square[2][2] = (sum - square[0][2] - square[1][2]);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << square[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}