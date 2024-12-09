#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sticks(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sticks[i];
    }

    int totalSticks = 0;
    int maxDetectives = n;
    for (int i = 0; i < n; i++) {
        totalSticks += sticks[i];
        if (totalSticks < i) {
            maxDetectives = i;
            break;
        }
    }

    std::cout << maxDetectives << std::endl;

    return 0;
}