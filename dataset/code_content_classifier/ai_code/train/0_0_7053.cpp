#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> bills(n);
    for (int i = 0; i < n; i++) {
        cin >> bills[i];
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        int x;
        cin >> x;
        
        int result = -1;
        
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                if (i * bills[0] + j * bills[1] == x || i * bills[1] + j * bills[0] == x) {
                    result = i + j;
                }
            }
        }
        
        cout << result << endl;
    }
    
    return 0;
}