#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long W;
    cin >> W;
    
    vector<int> items(8);
    for (int i = 0; i < 8; i++) {
        cin >> items[i];
    }
    
    long long maxWeight = 0;
    for (int mask = 0; mask < (1 << 8); mask++) {
        long long totalWeight = 0;
        
        for (int i = 0; i < 8; i++) {
            if (mask & (1 << i)) {
                totalWeight += (i + 1) * items[i];
            }
        }
        
        if (totalWeight <= W) {
            maxWeight = max(maxWeight, totalWeight);
        }
    }
    
    cout << maxWeight << endl;
    
    return 0;
}