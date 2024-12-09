#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> watched(n-1);
    for (int i = 0; i < n-1; i++) {
        std::cin >> watched[i];
    }

    std::sort(watched.begin(), watched.end());

    int missing_episode = -1;
    for (int i = 1; i <= n; i++) {
        if (std::find(watched.begin(), watched.end(), i) == watched.end()) {
            missing_episode = i;
            break;
        }
    }

    std::cout << missing_episode << std::endl;

    return 0;
}