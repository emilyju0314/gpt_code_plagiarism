#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> costs(n);
    for(int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    vector<int> totalCosts;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            totalCosts.push_back(costs[i] + costs[j]);
        }
    }

    sort(totalCosts.begin(), totalCosts.end());
    
    totalCosts.erase(unique(totalCosts.begin(), totalCosts.end()), totalCosts.end());

    for(int cost : totalCosts) {
        cout << cost << " ";
    }

    return 0;
}