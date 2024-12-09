#include <iostream>
#include <vector>

int main() {
    int N;
    while (std::cin >> N && N != 0) {
        std::vector<int> blocks(N);
        int total_blocks = 0;
        for (int i = 0; i < N; ++i) {
            std::cin >> blocks[i];
            total_blocks += blocks[i];
        }

        int operations = 0;
        while (true) {
            if (total_blocks == 0) {
                break;
            } else if (total_blocks % (N * (N + 1) / 2) != 0 || operations > 10000) {
                operations = -1;
                break;
            }

            int target = total_blocks / (N * (N + 1) / 2);
            int current = 0;
            bool updated = false;

            for (int i = 0; i < N; ++i) {
                current += blocks[i];
                if (current == target * (i + 1)) {
                    for (int j = 0; j <= i; ++j) {
                        if (blocks[j] > target) {
                            int diff = blocks[j] - target;
                            total_blocks -= diff;
                            blocks[j] = target;
                            for (int k = j - 1; k >= 0; --k) {
                                blocks[k] += diff;
                            }
                            updated = true;
                            ++operations;
                        }
                    }
                    current = 0;
                }
            }

            if (!updated) {
                operations = -1;
                break;
            }
        }

        std::cout << operations << std::endl;
    }

    return 0;
}