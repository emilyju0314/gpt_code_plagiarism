#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

int main() {
    int N, M, Q;
    while (true) {
        std::cin >> N >> M >> Q;
        if (N == 0 && M == 0 && Q == 0) {
            break;
        }

        std::vector<int> switches(36, 0);

        for (int i = 0; i < Q; ++i) {
            std::string S, B;
            std::cin >> S >> B;

            // Update the state of each switch based on operation
            for (int j = 0; j < N; ++j) {
                if (S[j] == '1') {
                    for (int k = 0; k < M; ++k) {
                        switches[j] |= 1 << k;
                    }
                }
            }

            // Check the state of each light bulb and update switches accordingly
            for (int j = 0; j < M; ++j) {
                bool lightOn = (B[j] == '1');
                int match = -1;
                for (int k = 0; k < N; ++k) {
                    if ((switches[k] & 1 << j) == (lightOn ? 1 << j : 0)) {
                        if (match == -1) {
                            match = k;
                        } else {
                            match = -2; // Multiple matches
                            break;
                        }
                    }
                }
                if (match >= 0) {
                    switches[match] |= 1 << j;
                }
            }
        }

        // Print the results in base-36
        for (int j = 0; j < M; ++j) {
            if ((switches[j] & -switches[j]) == switches[j]) {
                std::cout << std::hex << std::uppercase << ((int)std::log2(switches[j]));
            } else {
                std::cout << "?";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}