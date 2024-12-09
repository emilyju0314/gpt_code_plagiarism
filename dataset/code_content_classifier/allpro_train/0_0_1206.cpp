#include <iostream>

int main() {
    int n;
    
    while (std::cin >> n) {
        if (n == 0) break;
        
        int total_weight = 0;
        bool bridge_break = false;
        
        for (int i = 0; i < n; i++) {
            int weight, start_time, finish_time;
            std::cin >> weight >> start_time >> finish_time;
            
            total_weight += weight;
            
            if (total_weight > 150) {
                bridge_break = true;
            }
            
            total_weight -= weight;
        }
        
        if (bridge_break) {
            std::cout << "NG" << std::endl;
        } else {
            std::cout << "OK" << std::endl;
        }
    }
    
    return 0;
}