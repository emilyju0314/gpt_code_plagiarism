#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    long long l, r;
    cin >> l >> r;

    vector<pair<int, int>> pairs;
    bool found = false;

    for (int i = l; i <= r; i++) {
        for (int j = i + 1; j <= r; j++) {
            if (is_prime(i) && is_prime(j)) {
                pairs.push_back({i, j});
                found = true;
                break;
            }
        }
        if (found) {
            break;
        }
    }

    if (found) {
        cout << "YES" << endl;
        for (auto p : pairs) {
            cout << p.first << " " << p.second << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}