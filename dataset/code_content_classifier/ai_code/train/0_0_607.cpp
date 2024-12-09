#include <iostream>
#include <vector>

using namespace std;

bool canAchieveZero(int n, vector<int>& rotations) {
    for (int mask = 0; mask < (1 << n); mask++) {
        int total = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                total += rotations[i];
            } else {
                total -= rotations[i];
            }
        }
        total %= 360;
        if (total == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<int> rotations(n);
    for (int i = 0; i < n; i++) {
        cin >> rotations[i];
    }

    if (canAchieveZero(n, rotations)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}