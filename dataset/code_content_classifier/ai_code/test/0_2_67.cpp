#include <iostream>

int main() {
    int N;
    double P;
    std::cin >> N >> P;

    double prob = 0.0;
    int maps = 0;

    while (prob < P) {
        maps++;
        prob = 1.0 - pow((double)(N - maps) / N, maps);
    }

    std::cout << maps << std::endl;

    return 0;
}