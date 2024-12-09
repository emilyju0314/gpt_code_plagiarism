#include <iostream>
#include <vector>
#include <cmath>

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
    
    int tableSize = pow(2, K);
    vector<int> LSBTable(tableSize, 0);
    vector<int> MSBTable(tableSize, 0);
    
    bool possible = true;
    for (int i = 0; i < Q; i++) {
        int l = intervals[i].first;
        int r = intervals[i].second;
        int v = values[i];
        
        for (int j = l; j <= r; j++) {
            int LSBindex = j % tableSize;
            int MSBindex = j / tableSize;
            
            if (LSBTable[LSBindex] != 0 && LSBTable[LSBindex] != v) {
                possible = false;
                break;
            }
            LSBTable[LSBindex] = v;
            
            if (MSBTable[MSBindex] != 0 && MSBTable[MSBindex] != v) {
                possible = false;
                break;
            }
            MSBTable[MSBindex] = v;
        }
        
        if (!possible) {
            break;
        }
    }
    
    if (possible) {
        cout << "possible" << endl;
        for (int i = 0; i < tableSize; i++) {
            cout << LSBTable[i] << endl;
        }
        for (int i = 0; i < tableSize; i++) {
            cout << MSBTable[i] << endl;
        }
    } else {
        cout << "impossible" << endl;
    }
    
    return 0;
}