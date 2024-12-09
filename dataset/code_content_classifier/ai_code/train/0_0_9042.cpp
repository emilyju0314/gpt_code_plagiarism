#include <iostream>
#include <cmath>

using namespace std;

bool isPerfectSquare(int n) {
    int root = sqrt(n);
    return (root * root == n);
}

int main() {
    int n, m;
    cin >> n >> m;

    int rowSum = 1;
    int colSum = 1;
    int table[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            table[i][j] = rowSum * colSum;
            colSum += 2;
        }
        rowSum += 2;
        colSum = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}