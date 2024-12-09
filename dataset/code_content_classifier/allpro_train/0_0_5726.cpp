#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<pair<int, int>> p;
    
    for(int i = 0; i < n; ++i) {
        p.push_back({a[i], i});
    }
    
    sort(p.begin(), p.end(), greater<pair<int, int>>());
    
    vector<int> max_sum(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        max_sum[i] = max_sum[i-1] + p[i-1].first;
    }
    
    cin >> m;
    
    while(m--) {
        int k, pos;
        cin >> k >> pos;
        cout << p[pos - 1].first << endl;
    }
    
    return 0;
}