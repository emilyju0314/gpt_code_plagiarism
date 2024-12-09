#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    
    for(int i = 0; i < N; i++) {
        std::string rest;
        std::cin >> rest;
        
        int base, total_duration;
        std::vector<int> durations;
        
        for(int j = 0; j < rest.length(); j++) {
            if(rest[j] == 'R') {
                j++;
                base = rest[j] - '0';
                total_duration = base;
                j++;
                
                while(rest[j] == '.') {
                    total_duration += base / 2;
                    j++;
                }
                
                durations.push_back(total_duration);
            }
        }
        
        // Find the shortest expression
        int min_length = INT_MAX;
        std::string shortest_expression = "";
        
        do {
            std::string expression = "";
            for(int d : durations) {
                expression += "R" + std::to_string(d);
            }
            
            if(expression.length() < min_length) {
                min_length = expression.length();
                shortest_expression = expression;
            } else if(expression.length() == min_length) {
                shortest_expression = std::min(expression, shortest_expression);
            }
        } while(std::next_permutation(durations.begin(), durations.end()));
        
        std::cout << shortest_expression << std::endl;
    }
    
    return 0;
}