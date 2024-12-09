#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::string> initialNames(n);
    std::vector<std::string> targetNames(n);
    
    for(int i = 0; i < n; i++) {
        std::cin >> initialNames[i];
    }
    
    for(int i = 0; i < n; i++) {
        std::cin >> targetNames[i];
    }
    
    std::string s, t;
    bool possible = true;
    
    for(int i = 0; i < initialNames[0].size(); i++) {
        if(initialNames[0][i] != targetNames[0][i]) {
            s.push_back(initialNames[0][i]);
            t.push_back(targetNames[0][i]);
        } else if(s.size() > 0) {
            t.push_back(targetNames[0][i]);
        }
    }
    
    for(int i = 1; i < n; i++) {
        std::string newInitialName = initialNames[i];
        std::string newTargetName = targetNames[i];
        
        for(int j = 0; j < s.size(); j++) {
            size_t found = newInitialName.find(s[j]);
            if(found != std::string::npos) {
                newInitialName.replace(found, 1, " ");
            } else {
                possible = false;
                break;
            }
        }
        
        if(newInitialName != newTargetName) {
            possible = false;
        }
    }
    
    if(possible) {
        std::cout << "YES" << std::endl;
        std::cout << s << std::endl;
        std::cout << t << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}