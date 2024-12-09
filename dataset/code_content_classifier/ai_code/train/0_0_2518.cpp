#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int aCountS = 0, bCountS = 0, aCountT = 0, bCountT = 0;
    for (char c : s) {
        if (c == 'a') {
            aCountS++;
        } else {
            bCountS++;
        }
    }
    for (char c : t) {
        if (c == 'a') {
            aCountT++;
        } else {
            bCountT++;
        }
    }

    vector<pair<int, int>> swaps;

    // While both strings have both a's and b's
    while (aCountS > 0 && bCountS > 0 && aCountT > 0 && bCountT > 0) {
        // Swap a's and b's until one string has only a's and the other has only b's
        swaps.push_back({1, 1});
        aCountS--;
        bCountS--;
        aCountT--;
        bCountT--;
    }

    // If either string still has both a's and b's
    while (aCountS > 0 && bCountS > 0) {
        swaps.push_back({1, 0});
        aCountS--;
        bCountS--;
    }
    while (aCountT > 0 && bCountT > 0) {
        swaps.push_back({0, 1});
        aCountT--;
        bCountT--;
    }

    cout << swaps.size() << endl; // Output the number of operations
    for (auto p : swaps) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}