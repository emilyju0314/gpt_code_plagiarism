#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string s;
    std::cin >> s;
    
    int q;
    std::cin >> q;
    
    std::vector<int> impact_values;
    
    for (int i = 0; i < q; i++) {
        int query_type;
        std::cin >> query_type;
        
        if (query_type == 1) {
            int x;
            char c;
            std::cin >> x >> c;
            s[x-1] = c;
        } else if (query_type == 2) {
            int l, r;
            std::string e;
            std::cin >> l >> r >> e;
            
            int impact = 0;
            for (int j = l - 1; j <= r - 1; j++) {
                if (s[j] == e[(j - l + 1) % e.length()]) {
                    impact++;
                }
            }
            
            impact_values.push_back(impact);
        }
    }
    
    for (int impact : impact_values) {
        std::cout << impact << std::endl;
    }
    
    return 0;
}