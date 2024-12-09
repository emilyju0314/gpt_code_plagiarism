#include <iostream>
#include <string>
#include <vector>
#include <stack>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<std::string> strings(N);
    for(int i = 0; i < N; i++) {
        std::cin >> strings[i];
    }
    
    std::stack<char> stack;
    
    for(int i = 0; i < N; i++) {
        for(auto c : strings[i]) {
            if(c == '(') {
                stack.push(c);
            } else {
                if(stack.empty()) {
                    std::cout << "No" << std::endl;
                    return 0;
                }
                stack.pop();
            }
        }
    }
    
    if(stack.empty()) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    
    return 0;
}