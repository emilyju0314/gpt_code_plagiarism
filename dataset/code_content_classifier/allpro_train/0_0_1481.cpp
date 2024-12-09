#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    vector<pair<int, int>> pairs(t);
    for (int i = 0; i < t; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    cout << "0l";
    for (int i = 0; i < t; i++) {
        int a = pairs[i].first;
        int b = pairs[i].second;

        for (int j = 30; j >= 0; j--) {
            if (a & (1 << j)) {
                cout << "1";
            } else {
                cout << "0";
            }
            cout << "l";
        }

        cout << "0";
        
        for (int j = 30; j >= 0; j--) {
            if (b & (1 << j)) {
                cout << "1";
            } else {
                cout << "0";
            }
            cout << "l";
        }

        cout << "l0l1l1l0l0l0l1l1l1l0l1l0l1l1l0l0l0l1l0l1l1l1l0l0l0l1l0l0l0l0l1l0lr";
    }

    return 0;
}