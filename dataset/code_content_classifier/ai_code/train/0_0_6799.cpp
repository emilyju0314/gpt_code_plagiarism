#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> gasoline(n);
    for (int i = 0; i < n; i++) {
        std::cin >> gasoline[i];
    }
    
    std::vector<int> distances(n);
    for (int i = 0; i < n; i++) {
        std::cin >> distances[i];
    }
    
    int total_gasoline = 0;
    for (int i = 0; i < n; i++) {
        total_gasoline += gasoline[i];
    }
    
    std::vector<int> possible_starting_stations;
    for (int i = 0; i < n; i++) {
        int current_gasoline = total_gasoline;
        bool possible = true;
        for (int j = i; j < n; j++) {
            current_gasoline -= distances[j];
            if (current_gasoline < 0) {
                possible = false;
                break;
            }
        }
        if (possible) {
            for (int j = 0; j < i; j++) {
                current_gasoline -= distances[j];
                if (current_gasoline < 0) {
                    possible = false;
                    break;
                }
            }
        }
        if (possible) {
            possible_starting_stations.push_back(i + 1); // Add 1 to convert 0-based index to 1-based index
        }
    }
    
    std::cout << possible_starting_stations.size() << std::endl;
    for (int station : possible_starting_stations) {
        std::cout << station << " ";
    }
    
    return 0;
}