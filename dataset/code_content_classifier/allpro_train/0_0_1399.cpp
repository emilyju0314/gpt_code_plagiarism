#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<long long> events(n);
    vector<long long> intervals(m);
    
    for (int i = 0; i < n; i++) {
        cin >> events[i];
    }
    
    for (int i = 0; i < m; i++) {
        cin >> intervals[i];
    }
    
    for (int i = 1; i < n; i++) {
        if (events[i] - events[i-1] < intervals[0]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    for (int i = 1; i < m; i++) {
        if (intervals[i] % intervals[0] != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    cout << "YES" << endl;
    cout << events[0] << " 1" << endl;
    
    return 0;
}