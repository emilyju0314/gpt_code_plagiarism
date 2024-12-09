#include <iostream>
#include <vector>
#include <string>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<std::pair<std::string, int>> queries;
    
    for(int i = 0; i < n; i++) {
        std::string sign;
        int x;
        char answer;
        
        std::cin >> sign >> x >> answer;
        
        if(answer == 'Y') {
            if(sign == ">=") {
                queries.push_back({">", x});
            } else if(sign == "<=") {
                queries.push_back({"<", x});
            } else {
                queries.push_back({sign, x});
            }
        } else {
            if(sign == ">=") {
                queries.push_back({"<", x - 1});
            } else if(sign == "<=") {
                queries.push_back({">", x + 1});
            } else {
                if(sign == ">") {
                    queries.push_back({"<=", x});
                } else {
                    queries.push_back({">=", x});
                }
            }
        }
    }
    
    int y = 0;
    bool possible = true;
    
    for(auto query : queries) {
        std::string sign = query.first;
        int x = query.second;
        
        if(sign == ">") {
            y = std::max(y, x + 1);
        } else if(sign == "<") {
            y = std::min(y, x - 1);
        } else if(sign == ">=") {
            y = std::max(y, x);
        } else {
            y = std::min(y, x);
        }
        
        if(y < -2e9 || y > 2e9) {
            possible = false;
            break;
        }
    }
    
    if(possible) {
        std::cout << y << std::endl;
    } else {
        std::cout << "Impossible" << std::endl;
    }
    
    return 0;
}