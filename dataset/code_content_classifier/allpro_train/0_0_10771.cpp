#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int maxSum = 0;
    for(int i = 0; i < (n+1)/2; i++) {
        for(int j = 0; j < (n+1)/2; j++) {
            vector<int> vals = {board[i][j], board[i][n-1-j], board[n-1-i][j], board[n-1-i][n-1-j]};
            sort(vals.begin(), vals.end());

            int sum = vals[3] + vals[2];
            maxSum += sum;
        }
    }

    cout << maxSum << endl;

    return 0;
}