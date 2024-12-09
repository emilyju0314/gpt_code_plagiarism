#include <iostream>
#include <vector>

int lastRemainingCard(int N, int A, int B, std::string directionA, std::string directionB) {
    if (directionA != directionB) {
        return (A + B) % N;
    } else {
        return (A - B + N) % N;
    }
}

int main() {
    int T;
    std::cin >> T;

    for (int t = 0; t < T; t++) {
        int N, A, B;
        std::cin >> N >> A >> B;

        std::string directionA, directionB;
        std::cin >> directionA >> directionB;

        int result = lastRemainingCard(N, A, B, directionA, directionB);
        std::cout << result << std::endl;
    }

    return 0;
}