#include <iostream>
#include <string>

int main() {
    int n, k;
    std::string line;
    
    std::cin >> n >> k;
    std::cin.ignore();
    std::getline(std::cin, line);
    
    int start_pos = line.find('G');
    int target_pos = line.find('T');
    
    if ((start_pos - target_pos) % k != 0) {
        std::cout << "NO" << std::endl;
        return 0;
    }
    
    for (int i = start_pos; i != target_pos; i += (start_pos < target_pos) ? k : -k) {
        if (line[i] == '#') {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    
    std::cout << "YES" << std::endl;
    
    return 0;
}