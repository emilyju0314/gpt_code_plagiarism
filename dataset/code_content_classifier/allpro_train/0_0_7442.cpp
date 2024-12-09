#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> T(N);
    for (int i = 0; i < N; i++) {
        std::cin >> T[i];
    }

    std::sort(T.begin(), T.end(), std::greater<int>());

    int scanner1 = 0, scanner2 = 0, scanner3 = 0;
    for (int i = 0; i < N; i++) {
        if (scanner1 <= scanner2 && scanner1 <= scanner3) {
            scanner1 += T[i];
        } else if (scanner2 <= scanner1 && scanner2 <= scanner3) {
            scanner2 += T[i];
        } else {
            scanner3 += T[i];
        }
    }

    int max_time = std::max(scanner1, std::max(scanner2, scanner3));
    std::cout << max_time << std::endl;

    return 0;
}