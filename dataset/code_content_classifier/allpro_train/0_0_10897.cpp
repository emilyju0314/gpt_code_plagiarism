#include <iostream>
#include <string>
#include <set>

void backtrack(std::set<int>& options, std::string& current, std::set<std::string>& results) {
    if (current.size() == 14) {
        results.insert(current);
        return;
    }
    
    for (int num : options) {
        current.push_back(num + '0');
        backtrack(options, current, results);
        current.pop_back();
    }
}

int main() {
    std::string input;
    
    while (std::cin >> input) {
        std::set<int> counts;
        for (char c : input) {
            int num = c - '0';
            counts.insert(num);
        }
        
        std::set<int> options = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int num : counts) {
            options.erase(num);
        }
        
        std::set<std::string> results;
        std::string current = input;
        backtrack(options, current, results);
        
        if (results.empty()) {
            std::cout << "0" << std::endl;
        } else {
            for (auto& res : results) {
                std::cout << res << std::endl;
            }
        }
    }
    
    return 0;
}