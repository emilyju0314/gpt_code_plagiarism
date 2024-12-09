#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        
        vector<int> amounts(n);
        vector<int> weights(m);
        
        for (int i = 0; i < n; ++i) {
            cin >> amounts[i];
        }
        
        for (int i = 0; i < m; ++i) {
            cin >> weights[i];
        }
        
        sort(weights.begin(), weights.end());
        
        set<int> possibleSums;
        possibleSums.insert(0);
        
        for (int i = 0; i < m; ++i) {
            set<int> tempSums(possibleSums);
            for (int sum : tempSums) {
                possibleSums.insert(sum + weights[i]);
            }
        }
        
        int minWeight = 200;
        bool reachableAll = true;
        
        for (int amount : amounts) {
            if (possibleSums.find(amount) == possibleSums.end()) {
                reachableAll = false;
                for (int sum : possibleSums) {
                    int diff = amount - sum;
                    if (diff > 0) {
                        minWeight = min(minWeight, diff);
                    }
                }
            }
        }
        
        if (reachableAll) {
            cout << 0 << endl;
        } else if (minWeight == 200) {
            cout << -1 << endl;
        } else {
            cout << minWeight << endl;
        }
    }
    
    return 0;
}