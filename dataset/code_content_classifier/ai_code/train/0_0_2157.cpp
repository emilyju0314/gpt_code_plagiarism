#include <iostream>
#include <vector>

int main() {
    int n, m;
    
    while (std::cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        
        std::vector<int> taro(n);
        std::vector<int> hanako(m);
        
        for (int i = 0; i < n; i++) {
            std::cin >> taro[i];
        }
        
        for (int i = 0; i < m; i++) {
            std::cin >> hanako[i];
        }
        
        int taro_sum = 0;
        int hanako_sum = 0;
        
        for (int i = 0; i < n; i++) {
            taro_sum += taro[i];
        }
        
        for (int i = 0; i < m; i++) {
            hanako_sum += hanako[i];
        }
        
        bool exchange = false;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (taro_sum - taro[i] + hanako[j] == hanako_sum - hanako[j] + taro[i]) {
                    std::cout << taro[i] << " " << hanako[j] << std::endl;
                    exchange = true;
                    break;
                }
            }
            if (exchange) {
                break;
            }
        }
        
        if (!exchange) {
            std::cout << -1 << std::endl;
        }
    }
    
    return 0;
}