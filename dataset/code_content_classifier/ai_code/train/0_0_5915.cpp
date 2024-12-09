#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        
        int count = 0;
        for (int j = l; j <= r; j++) {
            int width = r - l + 1;
            int half_width = width / 2;
            if (j + half_width <= n) {
                bool match = true;
                for (int k = 0; k < half_width; k++) {
                    if (heights[j + k] + heights[j + half_width + k] != heights[l + k] + heights[l + half_width + k]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    count++;
                }
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}