#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    set<pair<int, int>> elements;
    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        elements.insert({r, c});
    }
    
    int ans = 0;
    set<pair<int, int>> visited;
    
    for (auto& p : elements) {
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (abs(dr) + abs(dc) != 1) continue;
                
                int r = p.first + dr;
                int c = p.second + dc;
                
                if (r >= 1 && r <= n && c >= 1 && c <= m && elements.count({r, c})) {
                    ans++;
                    visited.insert({r, c});
                }
            }
        }
    }
    
    cout << (n * m - q - ans) << endl;
    
    return 0;
}