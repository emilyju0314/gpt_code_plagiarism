#include <iostream>
#include <string>
#include <map>

bool isValidResults(const std::string& tournamentChart, const std::map<char, int>& wins) {
    int size = tournamentChart.size();
    
    auto it = wins.begin();
    for(int i = 0; i < size; i++) {
        if(tournamentChart[i] == '[') {
            int open = 1;
            int close = 0;
            int j = i + 1;
            
            while(open != close) {
                if(tournamentChart[j] == '[') {
                    open++;
                } else if(tournamentChart[j] == ']') {
                    close++;
                }
                
                j++;
            }
            
            std::string substring = tournamentChart.substr(i + 1, j - i - 2);
            if(!isValidResults(substring, wins)) {
                return false;
            }
            
            i = j - 1;
        } else {
            if(it == wins.end()) {
                return false;
            }
            
            if(it->second == 0) {
                return false;
            }
            
            it++;
        }
    }
    
    return true;
}

int main() {
    std::string tournamentChart;
    std::map<char, int> wins;
    int N;
    char contestant;
    int winsCount;
    
    std::cin >> tournamentChart;
    std::cin >> N;
    
    for(int i = 0; i < N; i++) {
        std::cin >> contestant >> winsCount;
        wins[contestant] = winsCount;
    }
    
    if(isValidResults(tournamentChart, wins)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    
    return 0;
}