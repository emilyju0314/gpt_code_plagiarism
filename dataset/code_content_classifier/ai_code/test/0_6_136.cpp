#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        long long total_sum = accumulate(b.begin(), b.end(), 0LL);
        bool possible = true;
        
        for (int i = 0; i < n; i++) {
            if (total_sum - b[i] <= 2 * b[i]) {
                possible = false;
                break;
            }
        }
        
        if (possible) {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++) {
                cout << 2 * b[i] << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}