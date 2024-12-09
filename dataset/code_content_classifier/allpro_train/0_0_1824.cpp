#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int factorial(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res = (1LL * res * i) % MOD;
    }
    return res;
}

int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = (1LL * res * a) % MOD;
        }
        a = (1LL * a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[matrix[0][i] - 1] = i;
    }
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        int inv_factorial = 1;
        for (int j = 0; j < pos[i]; j++) {
            inv_factorial = (1LL * inv_factorial * power(n - i, MOD - 2)) % MOD;
        }
        res = (1LL * res + ((1LL * factorial(n - i) * inv_factorial) % MOD)) % MOD;
        if (i < n - 1) {
            for (int j = pos[matrix[i + 1][pos[i]]]; j < n; j++) {
                if (matrix[i + 1][j] < matrix[i + 1][pos[i]]) {
                    pos[matrix[i + 1][j] - 1]--;
                }
            }
        }
    }
    
    cout << res << endl;
    
    return 0;
}