#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int m;
    cin >> m;
    
    vector<int> q(m);
    for(int i = 0; i < m; i++) {
        cin >> q[i];
    }
    
    sort(a.begin(), a.end(), greater<long long>());
    
    vector<long long> prefix_sum(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + a[i - 1];
    }
    
    for(int i = 0; i < m; i++) {
        long long total_amount = prefix_sum[q[i]] + (n - q[i]) * a[q[i] - 1];
        cout << total_amount << endl;
    }
    
    return 0;
}