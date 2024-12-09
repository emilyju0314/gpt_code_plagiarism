#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<long long> flavors(n);
        for(int i = 0; i < n; i++) {
            cin >> flavors[i];
        }
        
        long long min_coins = flavors[0];
        for(int i = 1; i < n; i++) {
            min_coins = min(min_coins, flavors[i]);
        }
        
        long long total_coins = min_coins + 2;
        
        cout << total_coins << endl;
    }
    
    return 0;
}