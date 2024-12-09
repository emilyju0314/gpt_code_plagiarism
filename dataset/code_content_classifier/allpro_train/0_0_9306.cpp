#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

bool canWin(std::vector<std::string> &strings) {
    std::unordered_map<std::string, bool> dp;
    
    for(const std::string &str : strings) {
        dp[str] = true;
    }
    
    while(true) {
        bool canMove = false;
        for(auto it = dp.begin(); it != dp.end(); ++it) {
            if(it->second) {
                for(char c = 'a'; c <= 'z'; ++c) {
                    std::string newWord = it->first + c;
                    bool found = false;
                    for(const std::string &str : strings) {
                        if(newWord == str.substr(0, newWord.size())) {
                            found = true;
                            break;
                        }
                    }
                    if(!found) {
                        dp[newWord] = true;
                        canMove = true;
                    }
                }
                it->second = false;
            }
        }
        
        if(!canMove) {
            break;
        }
    }
    
    bool firstPlayerWins = true;
    for(auto it = dp.begin(); it != dp.end(); ++it) {
        if(it->second) {
            firstPlayerWins = false;
            break;
        }
    }
    
    return firstPlayerWins;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<std::string> strings(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> strings[i];
    }
    
    if(canWin(strings)) {
        std::cout << "First" << std::endl;
    } else {
        std::cout << "Second" << std::endl;
    }
    
    return 0;
}