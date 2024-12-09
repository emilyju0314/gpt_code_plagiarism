#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> boxes(n);
        vector<int> special(m);
        
        for (int i = 0; i < n; i++) {
            cin >> boxes[i];
        }
        
        for (int i = 0; i < m; i++) {
            cin >> special[i];
        }
        
        sort(boxes.begin(), boxes.end());
        sort(special.begin(), special.end());
        
        int ans = 0;
        int j = 0;
        
        for (int i = 0; i < n; i++) {
            if (j < m && boxes[i] > special[j]) {
                j++;
                ans++;
            } else if (j == m) {
                break;
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}