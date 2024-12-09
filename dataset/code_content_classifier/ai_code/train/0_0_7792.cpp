#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<double> GPA(N);
    for(int i = 0; i < N; i++) {
        std::cin >> GPA[i];
    }

    for(int i = 0; i < N; i++) {
        int points = 0;
        for(int j = 0; j < N; j++) {
            if(i != j) {
                if(GPA[i] == GPA[j]) {
                    points += 1;
                } else if(GPA[i] > GPA[j]) {
                    points += 3;
                }
            }
        }
        std::cout << points << std::endl;
    }

    return 0;
}