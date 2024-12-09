#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> sectors(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> sectors[i];
    }

    int nextQuestion = k;

    while (sectors[nextQuestion - 1] == 0) {
        nextQuestion = (nextQuestion % n) + 1;
    }

    std::cout << nextQuestion << std::endl;

    return 0;
}