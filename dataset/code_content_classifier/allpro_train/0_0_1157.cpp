#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int t;
    std::cin >> t;
    
    for(int i = 0; i < t; i++) {
        int n, m;
        std::cin >> n >> m;
        
        std::vector<int> coordinates(n);
        std::vector<char> directions(n);
        
        for(int j = 0; j < n; j++) {
            std::cin >> coordinates[j];
        }
        
        for(int j = 0; j < n; j++) {
            std::cin >> directions[j];
        }
        
        std::unordered_map<int, int> pos_map;
        std::vector<int> result(n, -1);
        
        for(int j = 0; j < n; j++) {
            int current_pos = coordinates[j];
            int current_dir = (directions[j] == 'R') ? 1 : -1;
            
            while(true) {
                if(current_pos == 0 || current_pos == m) {
                    break;
                }
                
                if(pos_map.count(current_pos) > 0) {
                    result[j] = pos_map[current_pos];
                    result[pos_map[current_pos]] = -1;
                    break;
                }
                
                pos_map[current_pos] = j;
                current_pos += current_dir;
            }
        }
        
        for(int j = 0; j < n; j++) {
            std::cout << result[j] << " ";
        }
        
        std::cout << std::endl;
    }
    
    return 0;
}