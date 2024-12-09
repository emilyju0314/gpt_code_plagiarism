#include <iostream>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;
    
    std::unordered_map<int, int> home_kit_count;
    std::unordered_map<int, int> away_kit_count;
    
    for (int i = 0; i < n; i++) {
        int xi, yi;
        std::cin >> xi >> yi;
        
        home_kit_count[xi]++;
        away_kit_count[yi]++;
    }
    
    for (int i = 1; i <= n; i++) {
        int home_games = n-1 - away_kit_count[i] + home_kit_count[i];
        int away_games = n-1 - home_kit_count[i] + away_kit_count[i];
        
        std::cout << home_games << " " << away_games << std::endl;
    }
    
    return 0;
}