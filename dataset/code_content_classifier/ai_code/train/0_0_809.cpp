#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> threads(n);
    for (int i = 0; i < n; i++) {
        std::cin >> threads[i];
    }

    int answer = 0;
    int maxPosition = 0;

    for (int i = n - 1; i >= 0; i--) {
        if (threads[i] > maxPosition) {
            answer++;
        }
        maxPosition = std::max(maxPosition, threads[i]);
    }

    std::cout << answer << std::endl;

    return 0;
}