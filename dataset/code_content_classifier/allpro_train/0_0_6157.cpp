#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long getContribution(const vector<long long>& prices, int x, int a, int y, int b, long long k, int n) {
    vector<long long> contributions(n, 0);
    
    for (int i = 1; i <= n; ++i) {
        contributions[i-1] = prices[i-1] * (x + y) / 100;
            
        if (i % a == 0) contributions[i-1] -= prices[i-1] * x / 100;
        if (i % b == 0) contributions[i-1] -= prices[i-1] * y / 100;
    }
    
    sort(contributions.rbegin(), contributions.rend());
    
    long long total = 0;
    int tickets = 0;
    
    while (total < k && tickets < n) {
        total += contributions[tickets];
        ++tickets;
    }
    
    return total >= k ? tickets : -1;
}

int main() {
    int q;
    cin >> q;
    
    while (q--) {
        int n;
        cin >> n;
        
        vector<long long> prices(n);
        for (int i = 0; i < n; ++i) {
            cin >> prices[i];
        }
        
        int x, a, y, b;
        cin >> x >> a >> y >> b;
        
        long long k;
        cin >> k;
        
        cout << getContribution(prices, x, a, y, b, k, n) << endl;
    }
    
    return 0;
}