#include <iostream>
#include <map>

int main() {
    int n;
    std::cin >> n;
    
    std::map<int, std::map<int, int>> multiset;
    
    for (int i = 0; i < n; ++i) {
        int a, t, x;
        std::cin >> a >> t >> x;
        
        if (a == 1) {
            multiset[x][t]++;
        } else if (a == 2) {
            if (multiset[x][t] > 0) {
                multiset[x][t]--;
            }
        } else {
            int count = 0;
            for (auto it = multiset[x].begin(); it != multiset[x].end(); ++it) {
                if (it->first <= t) {
                    count += it->second;
                }
            }
            std::cout << count << std::endl;
        }
    }
    
    return 0;
}