#include <iostream>
#include <cmath>

int findLeafNode(int depth, int k) {
    if (depth == 0) {
        return 1;
    }

    int leftCount = pow(2, depth - 1);
    if (k <= leftCount) {
        return 2 * findLeafNode(depth - 1, k);
    }
    else {
        return 2 * findLeafNode(depth - 1, k - leftCount) + 1;
    }
}

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int D, K;
        std::cin >> D >> K;

        int result = findLeafNode(D, K);
        std::cout << result << std::endl;
    }

    return 0;
}