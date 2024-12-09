#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> events(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        std::cin >> events[i];
    }

    std::queue<int> shurikens;
    std::vector<int> order;

    for (int i = 0; i < 2 * n; i++) {
        if (events[i] == "+") {
            shurikens.push(i + 1);
        } else {
            int price = std::stoi(events[i].substr(2));
            if (shurikens.empty() || shurikens.front() > price) {
                std::cout << "NO" << std::endl;
                return 0;
            } else {
                order.push_back(shurikens.front());
                shurikens.pop();
            }
        }
    }

    std::cout << "YES" << std::endl;
    for (int o : order) {
        std::cout << o << " ";
    }

    return 0;
}