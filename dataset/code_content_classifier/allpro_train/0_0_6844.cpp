#include <iostream>
#include <vector>

bool possible(int a, int b) {
    // Check if the total score is valid
    if ((a % 25 == 0 && a != 0) || (b % 25 == 0 && b != 0)) {
        return false;
    }
    
    // Check if the total score difference is too big
    if (std::abs(a - b) > 2) {
        return false;
    }
    
    return true;
}

std::pair<int, int> get_sets(int a, int b) {
    // We start by having Team A win as many sets as possible
    int sets_a = a / 25;
    int sets_b = b / 25;
    
    // If one of the teams didn't reach required number of points
    if ((a % 25 == 24 && b < 24) || (b % 25 == 24 && a < 24)) {
        // Play one extra set
        sets_a++;
    }
    
    return {sets_a, sets_b};
}

int main() {
    int m;
    std::cin >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        
        if (!possible(a, b)) {
            std::cout << "Impossible" << std::endl;
        } else {
            std::pair<int, int> sets = get_sets(a, b);
            std::cout << sets.first << ":" << sets.second << std::endl;
            
            int remaining_a = a;
            int remaining_b = b;
            
            // Print the set scores
            for (int j = 0; j < sets.first + sets.second; j++) {
                int points_a = std::min(25, remaining_a);
                int points_b = std::min(25, remaining_b);
                
                std::cout << points_a << ":" << points_b << " ";
                
                remaining_a -= points_a;
                remaining_b -= points_b;
            }
            
            std::cout << std::endl;
        }
    }
    
    return 0;
}