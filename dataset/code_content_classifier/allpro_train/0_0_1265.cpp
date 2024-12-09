#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> tasks(n);
    int totalTasks = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> tasks[i];
        totalTasks += tasks[i];
    }

    int avgTasks = totalTasks / n;
    int remainingTasks = totalTasks % n;

    int minSeconds = 0;
    for (int i = 0; i < n; i++) {
        if (tasks[i] < avgTasks) {
            if (remainingTasks > 0) {
                minSeconds += avgTasks - tasks[i] - 1;
                remainingTasks--;
            } else {
                minSeconds += avgTasks - tasks[i];
            }
        }
    }

    std::cout << minSeconds << std::endl;

    return 0;
}