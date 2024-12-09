#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    sort(coins.begin(), coins.end());
    
    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;
        
        int count = 0;
        int index = n - 1;
        
        while (query > 0 && index >= 0) {
            if (coins[index] > query) {
                index--;
            } else {
                query -= coins[index];
                count++;
            }
        }
        
        if (query == 0) {
            cout << count << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}