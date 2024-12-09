#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        
        vector<int> denominations(n);
        for (int j = 0; j < n; j++) {
            cin >> denominations[j];
        }
        
        sort(denominations.begin(), denominations.end());
        
        int s = 1;
        bool found = false;
        
        while (true) {
            int target = s;
            int banknotes = 0;
            
            for (int j = n-1; j >= 0; j--) {
                int num_banknotes = target / (int)pow(10, denominations[j]);
                banknotes += num_banknotes;
                target -= num_banknotes * (int)pow(10, denominations[j]);
            }
            
            if (banknotes > k) {
                cout << s << endl;
                break;
            }
            
            s++;
        }
    }
    
    return 0;
}