#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> slices(N);
    for (int i = 0; i < N; i++) {
        std::cin >> slices[i];
    }

    int alice = 0, bob = 0;
    bool flag = true; // Initially Bob has the decider token

    for (int i = 0; i < N; i++) {
        if (flag) {
            bob += slices[i];
        } else {
            alice += slices[i];
        }
        flag = !flag; // Switching the decider token
    }

    std::cout << alice << " " << bob << std::endl;

    return 0;
}