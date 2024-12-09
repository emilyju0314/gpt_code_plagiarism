#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    map<int, vector<pair<int, int>>> sumToIndex;
    
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            sumToIndex[sum].push_back({i, j});
        }
    }
    
    for (auto it = sumToIndex.begin(); it != sumToIndex.end(); it++) {
        vector<pair<int, int>> blocks = it->second;
        if (blocks.size() > 1) {
            cout << blocks.size() << endl;
            for (auto block : blocks) {
                cout << block.first + 1 << " " << block.second + 1 << endl;
            }
            break;
        }
    }
    
    return 0;
}