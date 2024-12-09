#include <iostream>
#include <set>
#include <string>
#include <sstream>

int main() {
    int n;
    std::cin >> n;
    
    std::set<int> visitors;
    int min_capacity = 0;
    
    std::string log;
    getline(std::cin, log); // Clearing input buffer
    
    for (int i = 0; i < n; i++) {
        getline(std::cin, log);
        std::istringstream iss(log);
        
        char event;
        int id;
        
        iss >> event >> id;
        
        if (event == '+') {
            visitors.insert(id);
        } else if (event == '-') {
            if (visitors.find(id) != visitors.end()) {
                visitors.erase(id);
            } else {
                min_capacity++;
            }
        }
    }
    
    std::cout << min_capacity + visitors.size() << std::endl;
    
    return 0;
}