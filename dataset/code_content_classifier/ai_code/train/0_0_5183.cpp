#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

struct Item {
    string name;
    int price;
};

bool canCollectItems(int n, vector<vector<Item>>& supermarkets, vector<string>& requiredItems) {
    unordered_map<string, int> neededItems;
    
    for (const string& item : requiredItems) {
        neededItems[item] += 1;
    }
    
    for (const vector<Item>& supermarket : supermarkets) {
        for (const Item& item : supermarket) {
            if (neededItems.count(item.name) > 0) {
                neededItems[item.name] -= 1;
            }
        }
    }
    
    for (const auto& pair : neededItems) {
        if (pair.second > 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n;
    
    while (cin >> n && n != 0) {
        vector<vector<Item>> supermarkets(n);
        
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            
            for (int j = 0; j < k; j++) {
                string name;
                int price;
                cin >> name >> price;
                
                supermarkets[i].push_back({name, price});
            }
        }
        
        int q;
        cin >> q;
        
        vector<string> requiredItems(q);
        for (int i = 0; i < q; i++) {
            cin >> requiredItems[i];
        }
        
        int m;
        cin >> m;
        
        vector<vector<int>> distances(n+1, vector<int>(n+1, INT_MAX));
        
        while (m--) {
            int s, t, d;
            cin >> s >> t >> d;
            distances[s][t] = d;
            distances[t][s] = d;
        }
        
        int minAmount = INT_MAX;
        int minDistance = INT_MAX;
        
        do {
            if (canCollectItems(n, supermarkets, requiredItems)) {
                int amount = 0;
                
                for (int i = 1; i <= n; i++) {
                    amount += distances[0][i];
                }
                
                if (amount < minAmount) {
                    minAmount = amount;
                    minDistance = distances[0][0];
                } else if (amount == minAmount) {
                    minDistance = min(minDistance, distances[0][0]);
                }
            }
        } while (next_permutation(requiredItems.begin(), requiredItems.end()));
        
        if (minAmount != INT_MAX) {
            cout << minAmount << " " << minDistance << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
    
    return 0;
}