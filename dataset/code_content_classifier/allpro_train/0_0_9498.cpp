#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int q;
    cin >> q;
    
    vector<int> danger(106, 0);
    
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int l, r, k;
            cin >> l >> r >> k;
            
            for (int i = l; i < r; i++) {
                if (k < 0) {
                    if (danger[i] == 0 || abs(k) < abs(danger[i])) {
                        danger[i] = k;
                    }
                } else {
                    if (k > 0) {
                        danger[i] = max(danger[i], k);
                    }
                }
            }
        } else {
            int l, r;
            cin >> l >> r;
            
            int total_danger = 0;
            for (int i = l; i < r; i++) {
                if (danger[i] > 0) {
                    total_danger += danger[i];
                } else if (danger[i] < 0) {
                    total_danger += abs(danger[i]);
                }
            }
            
            cout << total_danger << endl;
        }
    }
    
    return 0;
}