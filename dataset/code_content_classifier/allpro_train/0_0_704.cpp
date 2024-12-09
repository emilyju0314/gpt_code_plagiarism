#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> beauty(N);
    std::vector<int> intellect(N);
    std::vector<int> richness(N);

    for (int i = 0; i < N; i++) {
        std::cin >> beauty[i];
    }

    for (int i = 0; i < N; i++) {
        std::cin >> intellect[i];
    }

    for (int i = 0; i < N; i++) {
        std::cin >> richness[i];
    }

    int num_self_murderers = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (beauty[i] < beauty[j] && intellect[i] < intellect[j] && richness[i] < richness[j]) {
                num_self_murderers++;
                break;
            }
        }
    }

    std::cout << num_self_murderers << std::endl;

    return 0;
}