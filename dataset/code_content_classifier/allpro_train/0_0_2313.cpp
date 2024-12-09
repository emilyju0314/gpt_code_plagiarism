#include <iostream>
#include <vector>

int main() {
    long long N, K;
    std::cin >> N >> K;

    std::vector<long long> capacities(K);
    for (int i = 0; i < K; i++) {
        std::cin >> capacities[i];
    }

    long long max_hamsters = 0, max_type = 1, max_boxes = 0;
    for (int i = 0; i < K; i++) {
        if (N % capacities[i] == 0) {
            long long num_boxes = N / capacities[i];
            if (num_boxes > max_boxes) {
                max_boxes = num_boxes;
                max_hamsters = N;
                max_type = i + 1;
            }
        } else {
            long long num_boxes = N / capacities[i] + 1;
            if (num_boxes * capacities[i] > max_hamsters) {
                max_boxes = num_boxes;
                max_hamsters = num_boxes * capacities[i];
                max_type = i + 1;
            }
        }
    }

    std::cout << max_type << " " << max_boxes << std::endl;

    return 0;
}