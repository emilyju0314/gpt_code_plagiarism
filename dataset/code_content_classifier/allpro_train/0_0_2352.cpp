#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<string> grid(n);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    int min_cost = 0;
    
    for(int h = n; h >= 1; h--) {
        for(int w = n; w >= 1; w--) {
            int cost = 0;
            for(int i = 0; i <= n - h; i++) {
                for(int j = 0; j <= n - w; j++) {
                    int black_cells = 0;
                    for(int k = i; k < i + h; k++) {
                        for(int l = j; l < j + w; l++) {
                            if(grid[k][l] == '#') {
                                black_cells++;
                            }
                        }
                    }
                    cost = max(cost, max(h, w) - black_cells);
                }
            }
            min_cost += cost;
        }
    }
    
    cout << min_cost << endl;
    
    return 0;
}