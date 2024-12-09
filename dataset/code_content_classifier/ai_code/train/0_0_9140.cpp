#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long T;
    cin >> T;

    // Find the smallest n and m such that n * m >= T
    int n, m;
    for (n = 1; n <= 50; n++) {
        for (m = 1; m <= 50; m++) {
            if (n * m >= T) {
                break;
            }
        }
        if (n * m >= T) {
            break;
        }
    }

    cout << n << " " << m << endl;

    int k = n + m - 2; // Minimum number of locked doors to ensure T number of ways
    cout << k << endl;

    vector<pair<int, int>> lockedDoors;

    // Lock doors to restrict number of ways to T
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (n * (m - j) + m * (n - i) - 2 == T) {
                lockedDoors.push_back({i, j, i, j + 1});
                lockedDoors.push_back({i, j, i + 1, j});
            }
        }
    }

    // Print locked doors
    for (auto door : lockedDoors) {
        cout << door.first << " " << door.second << " " << door.first + 1 << " " << door.second + 1 << endl;
    }

    return 0;
}