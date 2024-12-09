#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isPossible(vector<string>& field, int n, int m, int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (field[i][j] == '*') {
                bool valid = false;
                for (int d = k; d <= min(i, min(j, min(n-i-1, m-j-1))); d++) {
                    if (field[i-d][j-d] == '*' && field[i-d][j+d] == '*' && field[i+d][j-d] == '*' && field[i+d][j+d] == '*') {
                        valid = true;
                        break;
                    }
                }
                if (!valid) return false;
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<string> field(n);
        for (int i = 0; i < n; i++) {
            cin >> field[i];
        }

        if (isPossible(field, n, m, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}