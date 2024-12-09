#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    cin >> m;
    vector<int> q(m);
    for (int i = 0; i < m; i++) {
        cin >> q[i];
    }
    
    cin >> n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    
    sort(q.begin(), q.end());
    sort(prices.begin(), prices.end());
    
    int totalCost = 0;
    
    int discountIdx = 0;
    
    for (int i = n-1; i >= 0; i--) {
        if (discountIdx < m && q[discountIdx] >= n - i) {
            for (int j = 0; j < q[discountIdx]; j++) {
                totalCost += prices[i-j];
            }
            i -= q[discountIdx] - 1;
            discountIdx++;
        } else {
            totalCost += prices[i];
        }
    }
    
    cout << totalCost << endl;
    
    return 0;
}