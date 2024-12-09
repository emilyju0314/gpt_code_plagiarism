#include <iostream>
#include <vector>

using namespace std;

bool isSimilar(int x, int y) {
    return (x % 2 == y % 2) || (abs(x - y) == 1);
}

bool isPossiblePartition(vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        bool foundPair = false;
        for (int j = i + 1; j < a.size(); j++) {
            if (!isSimilar(a[i], a[j])) continue;
            foundPair = true;
            a.erase(a.begin() + j);
            break;
        }
        if (!foundPair) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (isPossiblePartition(a)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}