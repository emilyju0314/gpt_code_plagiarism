#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> w(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> w[i][j];
        }
    }

    for (int k = 1; k <= 1000000007; k++) {
        vector<int> a(n, 0);
        vector<int> b(m, 0);
        
        bool valid = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((a[i] | b[j]) % k != w[i][j]) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }

        if (valid) {
            cout << "YES" << endl;
            cout << k << endl;
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
            for (int j = 0; j < m; j++) {
                cout << b[j] << " ";
            }
            cout << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}