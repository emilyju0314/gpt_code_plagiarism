#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> flavors(n);
        for(int i = 0; i < n; i++) {
            cin >> flavors[i];
        }
        
        int min_coins = 1000000000; // Initialize with a large value
        
        for(int i = 0; i < n; i++) {
            int coins = 0;
            // Calculate the minimum number of coins needed for each flavor
            coins += (flavors[i] / 3) * 2;
            coins += (flavors[i] % 3 == 2) ? 1 : 0;
            
            min_coins = min(min_coins, coins);
        }
        
        cout << min_coins << endl;
    }
    
    return 0;
}