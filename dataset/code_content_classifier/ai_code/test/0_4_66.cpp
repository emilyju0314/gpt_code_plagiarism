#include <iostream>
#include <string>

int lastRemainingCard(int N, int A, int B, std::string D_A, std::string D_B) {
    int direction = (D_A == "left") ? -1 : 1;
    int remainingCards = N;

    while (remainingCards > 1) {
        int distance = (B - A) / (2 * direction);
        if ((B - A) % 2 != 0) {
            direction *= -1;
        }

        int diff = (B - A) / direction;

        B = (D_B == "left") ? B - diff : B + diff;
        A = (B == N) ? 0 : B;

        if (A == B) {
            remainingCards--;
            if (B == N - 1) {
                B--;
            }
        }
    }

    return B;
}

int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        int N, A, B;
        std::string D_A, D_B;
        std::cin >> N >> A >> B >> D_A >> D_B;

        int result = lastRemainingCard(N, A, B, D_A, D_B);

        std::cout << result << std::endl;
    }

    return 0;
}