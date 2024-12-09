#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    
    vector<int> frontColors(n);
    for (int i = 0; i < n; i++) {
        cin >> frontColors[i];
    }
    
    vector<int> backColors(n);
    for (int i = 0; i < n; i++) {
        cin >> backColors[i];
    }
    
    int m;
    cin >> m;
    
    vector<int> buyers(m);
    for (int i = 0; i < m; i++) {
        cin >> buyers[i];
    }
    
    map<int, int> minPrice;
    
    for (int i = 0; i < n; i++) {
        if (minPrice.find(frontColors[i]) == minPrice.end() || prices[i] < minPrice[frontColors[i]]) {
            minPrice[frontColors[i]] = prices[i];
        }
        
        if (minPrice.find(backColors[i]) == minPrice.end() || prices[i] < minPrice[backColors[i]]) {
            minPrice[backColors[i]] = prices[i];
        }
    }
    
    for (int i = 0; i < m; i++) {
        if (minPrice.find(buyers[i]) != minPrice.end()) {
            cout << minPrice[buyers[i]] << " ";
        } else {
            cout << -1 << " ";
        }
    }
    
    return 0;
}