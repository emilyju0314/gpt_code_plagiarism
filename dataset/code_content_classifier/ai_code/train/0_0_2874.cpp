#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int K, Q;
    cin >> K >> Q;

    vector<pair<int, int>> intervals(Q);
    vector<int> values(Q);

    for (int i = 0; i < Q; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        intervals[i] = {l, r};
        values[i] = v;
    }

    unordered_map<int, int> LSBTable;
    unordered_map<int, int> MSBTable;

    bool possible = true;

    for (int i = 0; i < Q; i++) {
        for (int x = intervals[i].first; x <= intervals[i].second; x++) {
            int LSBVal = values[i] & 0xFFFF;
            int MSBVal = values[i] & 0xFFFF0000;

            if (LSBTable.count(x & ((1 << K) - 1)) && LSBTable[x & ((1 << K) - 1)] != LSBVal) {
                possible = false;
                break;
            }

            if (MSBTable.count(x >> K) && MSBTable[x >> K] != MSBVal) {
                possible = false;
                break;
            }

            LSBTable[x & ((1 << K) - 1)] = LSBVal;
            MSBTable[x >> K] = MSBVal;
        }
    }

    if (possible) {
        cout << "possible" << endl;
        
        for (int i = 0; i < (1 << K); i++) {
            cout << LSBTable[i] << endl;
        }

        for (int i = 0; i < (1 << K); i++) {
            cout << MSBTable[i] << endl;
        }
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}