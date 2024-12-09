#include <iostream>
#include <set>

int main() {
    int n;
    std::cin >> n;
    
    std::set<int> operations;
    
    for(int i = 0; i < n; i++) {
        char op;
        int x;
        std::cin >> op >> x;
        
        if(op == '|') {
            operations.insert(x);
        } else if(op == '&') {
            std::set<int> new_operations;
            for(int num : operations) {
                new_operations.insert(num & x);
            }
            operations = new_operations;
        } else if(op == '^') {
            std::set<int> new_operations;
            for(int num : operations) {
                new_operations.insert(num ^ x);
            }
            operations = new_operations;
        }
    }
    
    std::cout << operations.size() << std::endl;
    for(int num : operations) {
        std::cout << "| " << num << std::endl;
    }
    
    return 0;
}