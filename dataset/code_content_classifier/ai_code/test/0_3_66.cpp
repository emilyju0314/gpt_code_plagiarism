#include <iostream>
#include <string>

int main() {
    int T;
    std::cin >> T;

    for (int t = 0; t < T; t++) {
        long long N;
        int A, B;
        std::string D_A, D_B;

        std::cin >> N >> A >> B >> D_A >> D_B;

        long long remaining = N;
        long long diff = B - A;

        if (D_A == "right") {
            A = (A + diff + N) % N;
            D_A = "left";
        }

        if (D_B == "left") {
            B = (B - diff + N) % N;
            D_B = "right";
        }

        remaining -= std::abs(A - B) / 2;
        remaining -= (N - 1) / 2;

        std::cout << (remaining + N) % N << std::endl;
    }

    return 0;
}