#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> powers(n);
    for (int i = 0; i < n; i++) {
        cin >> powers[i];
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        long long cumulative_power = 1;
        for (int i = l-1; i < r; i++) {
            cumulative_power = (cumulative_power * powers[i]) % m;
        }
        
        cout << cumulative_power << endl;
    }
    
    return 0;
}