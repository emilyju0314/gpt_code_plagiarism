#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> coins(n + 1);
    for(int i = 1; i <= n; i++) {
        std::cin >> coins[i];
    }

    std::vector<int> indexes(n + 1);
    for(int i = 1; i <= n; i++) {
        indexes[coins[i]] = i;
    }

    std::vector<int> hardness(n + 1);
    int max_steps = 1;
    for(int i = 1; i <= n; i++) {
        hardness[i] = std::max(hardness[i - 1], indexes[i]);
        max_steps = std::max(max_steps, i - hardness[i] + 1);
    }

    for(int i = 0; i <= n; i++) {
        std::cout << max_steps + i << " ";
    }

    return 0;
}