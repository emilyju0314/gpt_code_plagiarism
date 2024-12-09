#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, n;
    
    while (cin >> m >> n) {
        if (m == 0 && n == 0) {
            break;
        }
        
        vector<vector<int>> map(m, vector<int>(n, 0));
        
        int s;
        cin >> s;
        for (int i = 0; i < s; i++) {
            int x, y;
            cin >> x >> y;
            map[x-1][y-1] = -1;
        }
        
        int t;
        cin >> t;
        vector<int> max_blocks(t, 0);
        
        for (int i = 0; i < t; i++) {
            int p, q;
            cin >> p >> q;
            
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n; y++) {
                    if (map[x][y] == 0) {
                        int min_dist = INT_MAX;
                        
                        for (int j = 0; j < s; j++) {
                            int dist = abs(p-1-x) + abs(q-1-y);
                            if (dist < min_dist) {
                                min_dist = dist;
                                map[x][y] = j+1;
                            } else if (dist == min_dist) {
                                map[x][y] = 0;
                            }
                        }
                    }
                }
            }
            
            int count = 0;
            for (int x = 0; x < m; x++) {
                for (int y = 0; y < n; y++) {
                    if (map[x][y] == i+1) {
                        count++;
                    }
                }
            }
            
            max_blocks[i] = count;
        }
        
        cout << *max_element(max_blocks.begin(), max_blocks.end()) << endl;
    }
    
    return 0;
}