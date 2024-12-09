#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int N, A, B, C, X;

    while (true) {
        std::cin >> N >> A >> B >> C >> X;

        if (N == 0 && A == 0 && B == 0 && C == 0 && X == 0) {
            break;
        }

        std::vector<int> Y(N);
        for (int i = 0; i < N; i++) {
            std::cin >> Y[i];
        }

        int frames = 0;
        int x = X;
        bool success = true;
        for (int i = 0; i < 10000; i++) {
            bool valid = true;
            for (int j = 0; j < N; j++) {
                if (x != Y[j]) {
                    valid = false;
                    break;
                }
                x = (A * x + B) % C;
            }

            if (valid) {
                success = true;
                frames = i;
                break;
            }
        }

        if (success) std::cout << frames << std::endl;
        else std::cout << -1 << std::endl;
    }

    return 0;
}