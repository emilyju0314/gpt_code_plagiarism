#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> tasks(n);
    for (int i = 0; i < n; i++) {
        std::cin >> tasks[i];
    }

    std::unordered_map<int, std::vector<int>> taskIndices;
    for (int i = 0; i < n; i++) {
        taskIndices[tasks[i]].push_back(i);
    }

    std::vector<int> plan1, plan2, plan3;
    bool possible = true;

    for (auto& task : taskIndices) {
        if (task.second.size() >= 3) {
            possible = false;
            break;
        }

        if (task.second.size() == 2) {
            plan1.push_back(task.second[0]);
            plan2.push_back(task.second[1]);
            plan3.push_back(task.second[1]);
        }

        if (task.second.size() == 1) {
            plan1.push_back(task.second[0]);
            plan2.push_back(task.second[0]);
            plan3.push_back(task.second[0]);
        }
    }

    if (!possible) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
        for (int i = 0; i < n; i++) {
            if (i != 0) std::cout << " ";
            std::cout << plan1[i] + 1;
        }
        std::cout << std::endl;

        for (int i = 0; i < n; i++) {
            if (i != 0) std::cout << " ";
            std::cout << plan2[i] + 1;
        }
        std::cout << std::endl;

        for (int i = 0; i < n; i++) {
            if (i != 0) std::cout << " ";
            std::cout << plan3[i] + 1;
        }
        std::cout << std::endl;
    }

    return 0;
}