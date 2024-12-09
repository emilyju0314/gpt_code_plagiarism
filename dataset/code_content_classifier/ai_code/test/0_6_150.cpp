#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> flavors(n);
        for (int i = 0; i < n; i++) {
            cin >> flavors[i];
        }
        
        int min_coins = *min_element(flavors.begin(), flavors.end());
        int max_coins = *max_element(flavors.begin(), flavors.end());
        
        int min_total = min_coins + min(2, min_coins);
        
        cout << min_total << endl;
    }

    return 0;
}