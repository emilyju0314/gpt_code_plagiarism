#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Helper function to check if a given address matches a pattern
bool matchPattern(const std::string& address, const std::string& pattern) {
    for (int i = 0; i < 8; i++) {
        if (pattern[i] != '?' && pattern[i] != address[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    
    while (std::cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        
        // Read filtering rules
        std::vector<std::pair<std::string, std::pair<std::string, std::string>>> rules;
        for (int i = 0; i < n; i++) {
            std::string keyword, source, dest;
            std::cin >> keyword >> source >> dest;
            rules.push_back({ keyword, { source, dest } });
        }
        
        // Read and apply packets
        int legalCount = 0;
        for (int i = 0; i < m; i++) {
            std::string source, dest, message;
            std::cin >> source >> dest >> message;
            
            bool legal = false;
            for (const auto& rule : rules) {
                if ((rule.first == "permit" && matchPattern(source, rule.second.first) && matchPattern(dest, rule.second.second))
                    || (rule.first == "deny" && matchPattern(source, rule.second.first) && matchPattern(dest, rule.second.second))) {
                    legal = (rule.first == "permit");
                    break;
                }
            }
            
            if (legal) {
                legalCount++;
                std::cout << source << " " << dest << " " << message << std::endl;
            }
        }
        
        std::cout << legalCount << std::endl;
    }
    
    return 0;
}