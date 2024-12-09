#include <iostream>
#include <stack>
#include <unordered_map>

int main() {
    int m;
    std::cin >> m;

    std::unordered_map<char, std::pair<int, int>> variables;

    for(int i = 0; i < m; i++) {
        char name;
        int lb, ub;
        std::cin >> name >> lb >> ub;
        variables[name] = std::make_pair(lb, ub);
    }

    int n;
    std::cin >> n;

    std::stack<int> s;

    for(int i = 0; i < n; i++) {
        std::string element;
        std::cin >> element;

        if(isdigit(element[0])) {
            s.push(std::stoi(element));
        } else if(variables.find(element[0]) != variables.end()) {
            s.push(variables[element[0]].first);
        } else {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();

            int r;

            switch(element[0]) {
                case '+':
                    r = (a + b) % 256;
                    break;
                case '-':
                    r = (a - b + 256) % 256;
                    break;
                case '*':
                    r = (a * b) % 256;
                    break;
                case '/':
                    if(b == 0) {
                        std::cout << "error" << std::endl;
                        return 0;
                    }
                    r = (a / b) % 256;
                    break;
            }

            s.push(r);
        }
    }

    std::cout << "correct" << std::endl;
    
    return 0;
}