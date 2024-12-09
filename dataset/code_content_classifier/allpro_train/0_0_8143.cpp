#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> actions;

    // Calculate the number of actions needed to turn over all skewers
    int num_actions = (n + 2*k - 1) / (2*k);

    // Determine the skewers to be turned over in each step
    for (int i = 0; i < num_actions; i++) {
        actions.push_back(k + 1 + 2 * k * i);
    }

    // Output the minimum number of actions and the skewer numbers to turn over
    std::cout << num_actions << std::endl;
    for (int i = 0; i < actions.size(); i++) {
        std::cout << actions[i] << " ";
    }

    return 0;
}