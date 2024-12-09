#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    bool found_positive_k = false;
    for (int i = 0; i < n; i++) {
        bool all_positive = true;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) {
                all_positive = false;
                break;
            }
        }
        if (all_positive) {
            found_positive_k = true;
            break;
        }
    }

    if (found_positive_k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}