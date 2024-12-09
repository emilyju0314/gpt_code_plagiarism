#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxSocksOnTable(int n, vector<int>& order) {
    unordered_map<int, int> pairs;
    int maxSocks = 0;
    
    for(int i = 0; i < order.size(); i++) {
        if(pairs.find(order[i]) == pairs.end()) {
            pairs[order[i]] = 1;
        } else {
            pairs.erase(order[i]);
        }
        
        maxSocks = max(maxSocks, (int)pairs.size());
    }
    
    return maxSocks;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> order(2*n);
    for(int i = 0; i < 2*n; i++) {
        cin >> order[i];
    }
    
    cout << maxSocksOnTable(n, order) << endl;
    
    return 0;
}