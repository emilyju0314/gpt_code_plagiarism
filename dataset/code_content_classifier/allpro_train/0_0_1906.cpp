#include <iostream>
#include <stack>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;
    
    std::vector<std::stack<int>> stacks(n);

    for (int i = 0; i < q; i++) {
        int operation, t, x;
        std::cin >> operation >> t;

        if (operation == 0) {
            std::cin >> x;
            stacks[t].push(x);
        } else if (operation == 1) {
            if (!stacks[t].empty()) {
                std::cout << stacks[t].top() << std::endl;
            }
        } else if (operation == 2) {
            if (!stacks[t].empty()) {
                stacks[t].pop();
            }
        }
    }

    return 0;
}