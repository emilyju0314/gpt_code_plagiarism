#include <iostream>
#include <map>
#include <vector>

int main() {
    std::map<std::string, std::vector<int>> word_map;
    
    std::string word;
    int page_number;
    
    while(std::cin >> word >> page_number) {
        word_map[word].push_back(page_number);
    }
    
    for (const auto& pair : word_map) {
        std::cout << pair.first << std::endl;
        
        std::vector<int> page_numbers = pair.second;
        sort(page_numbers.begin(), page_numbers.end());
        
        for (int i : page_numbers) {
            std::cout << i << " ";
        }
        
        std::cout << std::endl;
    }
    
    return 0;
}