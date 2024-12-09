#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k, L;
    cin >> n >> k >> L;
    
    vector<vector<int>> candies(L, vector<int>(L, 0)); // Initialize grid of candies
    
    for (int i = 0; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        candies[x][y] = c;
    }
    
    long long ans = 0;
    
    for (int X1 = 0; X1 < L; X1++) {
        for (int X2 = X1 + 1; X2 < L; X2++) {
            vector<int> colors(k, 0);
            int cnt = 0;
            
            for (int y = 0; y < L; y++) {
                for (int x = X1; x < X2; x++) {
                    if (candies[x][y] != 0 && colors[candies[x][y] - 1] == 0) {
                        colors[candies[x][y] - 1] = 1;
                        cnt++;
                    }
                }
                if (cnt == k) {
                    ans = (ans + (X2 - X1) * (y + 1)) % MOD;
                    break;
                }
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}