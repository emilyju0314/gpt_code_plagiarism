#include <iostream>
#include <string>

int main() {
    std::string query;
    
    while (std::cin >> query) {
        if (query == "#") {
            break;
        }
        
        std::string text;
        std::cin >> text;
        
        bool found = false;
        
        for (int i = query.size(); i <= text.size(); ++i) {
            bool contains_query = true;
            for (int j = 0; j < query.size(); ++j) {
                if (text.substr(i - query.size(), query.size()) != query) {
                    contains_query = false;
                    break;
                }
            }
            
            if (!contains_query) {
                std::cout << i << std::endl;
                found = true;
                break;
            }
        }
        
        if (!found) {
            std::cout << "No Results" << std::endl;
        }
    }
    
    return 0;
}