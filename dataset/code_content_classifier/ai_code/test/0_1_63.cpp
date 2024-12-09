#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    int total_open = 0;
    int max_prefixes = 0;

    for(int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;

        int open = 0;
        int close = 0;

        for(char c : s){
            if(c == '('){
                open++;
            } else {
                if(open > 0){
                    open--;
                } else {
                    close++;
                }
            }
        }
        
        total_open += open;
        
        max_prefixes += std::min(open, close);
    }

    max_prefixes += total_open % 2;

    std::cout << max_prefixes << std::endl;

    return 0;
}