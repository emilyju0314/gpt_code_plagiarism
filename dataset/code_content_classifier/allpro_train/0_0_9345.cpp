#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    
    while (std::cin >> n, n) {
        std::vector<std::vector<int>> watches(n, std::vector<int>(3));
        for (int i = 0; i < n; ++i) {
            std::cin >> watches[i][0] >> watches[i][1] >> watches[i][2];
        }
        
        std::vector<int> mins(n);
        for (int i = 0; i < n; ++i) {
            mins[i] = watches[i][1] * 60 + watches[i][2];
        }
        
        std::sort(mins.begin(), mins.end());
        
        int l = 0, r = -1;
        int res_l = 0, res_r = 86400;
        
        while (true) {
            ++r;
            if (r == n) break;
            while (mins[r] - mins[l] > 60) {
                ++l;
            }
            if (mins[r] - mins[l] < 60 && mins[r] - mins[l] < res_r - res_l) {
                res_l = mins[l];
                res_r = mins[r];
            }
        }
        
        printf("%02d:%02d:%02d %02d:%02d:%02d\n", res_l / 3600, (res_l / 60) % 60, res_l % 60, res_r / 3600, (res_r / 60) % 60, res_r % 60);
    }
    
    return 0;
}