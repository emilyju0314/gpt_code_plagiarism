#include <iostream>
#include <string>
#include <map>

int main() {
    int n, m;
    while (std::cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        
        std::map<std::string, int> winnings;
        for (int i = 0; i < n; i++) {
            std::string winning_number;
            int amount;
            std::cin >> winning_number >> amount;
            winnings[winning_number] = amount;
        }
        
        int total_winnings = 0;
        for (int i = 0; i < m; i++) {
            std::string lottery_number;
            std::cin >> lottery_number;
            
            for (const auto& pair : winnings) {
                std::string winning_number = pair.first;
                int amount = pair.second;
                
                bool match = true;
                for (int j = 0; j < 8; j++) {
                    if (winning_number[j] != '*' && winning_number[j] != lottery_number[j]) {
                        match = false;
                        break;
                    }
                }
                
                if (match) {
                    total_winnings += amount;
                }
            }
        }
        
        std::cout << total_winnings << std::endl;
    }
    
    return 0;
}