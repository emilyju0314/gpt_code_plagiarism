#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> beavers(n);
    for (int i = 0; i < n; i++) {
        cin >> beavers[i];
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int p, x, y;
        cin >> p >> x >> y;
        
        if (p == 1) {
            // Find the minimum number of sessions needed to shave beavers from x to y
            int sessions = 1;
            int prev = beavers[x-1];
            
            for (int i = x; i <= y; i++) {
                if (beavers[i-1] < prev) {
                    sessions += 1;
                }
                prev = beavers[i-1];
            }
            
            cout << sessions << endl;
        } else if (p == 2) {
            // Swap two beavers on positions x and y
            swap(beavers[x-1], beavers[y-1]);
        }
    }
    
    return 0;
}