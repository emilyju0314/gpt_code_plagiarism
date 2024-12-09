// C++ program to implement the given problem
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<tuple<int, int, int>> operations;
    for (int i = 0; i < m; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        operations.push_back(make_tuple(l, r, d));
    }
    
    vector<pair<int, int>> queries;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        queries.push_back(make_pair(x, y));
    }
    
    vector<long long> diff(m + 1, 0);
    
    for (auto query : queries) {
        int x = query.first;
        int y = query.second;
        diff[x - 1]++;
        diff[y]--;
    }
    
    for (int i = 1; i < m; i++) {
        diff[i] += diff[i - 1];
    }
    
    for (int i = 0; i < m; i++) {
        int l, r, d;
        tie(l, r, d) = operations[i];
        diff[i] *= d;
        a[l-1] += diff[i];
        if (r < n) {
            a[r] -= diff[i];
        }
    }
    
    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }
    
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}