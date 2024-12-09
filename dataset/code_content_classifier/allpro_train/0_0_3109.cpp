#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    std::string color;
    
    while (std::cin >> color) {
        std::vector<std::string> panels;
        panels.push_back(color);
        
        for (int i = 1; i < 8; i++) {
            std::cin >> color;
            panels.push_back(color);
        }
        
        std::sort(panels.begin(), panels.end());
        
        std::unordered_set<std::string> unique_panels;
        
        do {
            std::string panel = panels[0] + panels[1] + panels[2];
            for (int i = 3; i < 6; i++) {
                panel += panels[i];
            }
            unique_panels.insert(panel);
        } while (std::next_permutation(panels.begin(), panels.end()));
        
        int num_unique_panels = unique_panels.size();
        int num_possible_octahedra = factorial(8) / (8 * factorial(6)) * num_unique_panels / 24;
        
        std::cout << num_possible_octahedra << std::endl;
    }
    
    return 0;
}