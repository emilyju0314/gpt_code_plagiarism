#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isMirrored(vector<vector<int>>& a, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (a[i][j] != a[2*x-i-1][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int x = n;
    while (x > 0) {
        if (x % 2 == 0 && isMirrored(a, x/2, m)) {
            cout << x << endl;
            return 0;
        }
        x--;
    }
    
    return 0;
}