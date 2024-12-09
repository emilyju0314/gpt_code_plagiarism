#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int maxMex = 0;
    vector<pair<int, int>> subarrays;
    
    for(int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        subarrays.push_back({l, r});
        maxMex = max(maxMex, r - l + 1);
    }
    
    cout << maxMex << endl;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        arr[i] = i % maxMex;
    }
    
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}