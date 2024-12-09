#include <iostream>
#include <vector>

using namespace std;

bool checkSumIsSquare(int num1, int num2) {
    int sum = num1*num1 + num2*num2;
    int root = sqrt(sum);
    return root*root == sum;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> table(n, vector<int>(m, 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int num = 2;
            while (!checkSumIsSquare(table[i][0], num) || !checkSumIsSquare(table[0][j], num)) {
                num++;
            }
            table[i][j] = num;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}