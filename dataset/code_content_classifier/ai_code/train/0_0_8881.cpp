#include <iostream>
#include <stack>
#include <vector>

int main() {
    int m;
    std::cin >> m;
    
    std::vector<int> operationType(m+1);
    std::vector<int> operationValue(m+1);
    std::vector<int> result(m+1, -1); // Initialize result with -1
    
    for(int i = 1; i <= m; i++) {
        int pi, ti;
        std::cin >> pi >> ti;
        
        operationType[pi] = ti;
        
        if(ti == 1) {
            int xi;
            std::cin >> xi;
            operationValue[pi] = xi;
        }
    }
    
    std::stack<int> stack;
    
    for(int i = 1; i <= m; i++) {
        if(operationType[i] == 1) { // push(x)
            stack.push(operationValue[i]);
        } else { // pop()
            if(!stack.empty()) {
                stack.pop();
            }
        }
        
        if(!stack.empty()) {
            result[i] = stack.top();
        }
    }
    
    for(int i = 1; i <= m; i++) {
        std::cout << result[i] << std::endl;
    }
    
    return 0;
}