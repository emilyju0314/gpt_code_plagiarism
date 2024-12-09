#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n;
    
    vector<int> stones(n);
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }
    
    cin >> q;
    vector<int> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }
    
    sort(stones.begin(), stones.end(), greater<int>());
    
    long long totalCost = 0;
    for (int i = 0; i < n; i++) {
        totalCost += (long long) stones[i] * i;
    }
    
    for (int i = 0; i < q; i++) {
        cout << totalCost << " ";
        totalCost = 0;
        for (int j = 0; j < n; j += queries[i]) {
            totalCost += (long long) stones[j] * (j/queries[i] + 1);
        }
    }
    
    return 0;
}