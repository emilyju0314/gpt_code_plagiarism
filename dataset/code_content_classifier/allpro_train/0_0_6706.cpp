#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> heights(n);
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    
    int m;
    cin >> m;
    
    for(int i = 0; i < m; i++) {
        int l, r, w;
        cin >> l >> r >> w;
        
        int minHeight = *min_element(heights.begin() + l - 1, heights.begin() + r);
        int maxHeight = 0;
        
        for(int j = 0; j <= r - l - w + 1; j++) {
            maxHeight = max(maxHeight, min(heights[l + j - 1], minHeight));
        }
        
        cout << maxHeight << endl;
    }
    
    return 0;
}