#include <iostream>
#include <iomanip>

int main() {
    int N;
    double P;
    std::cin >> N >> P;

    int maps_to_study = 0;
    double current_probability = 1.0;

    while (current_probability > 1 - P) {
        maps_to_study++;
        current_probability *= (double)(N - maps_to_study) / N;
    }

    std::cout << maps_to_study << std::endl;

    return 0;
}