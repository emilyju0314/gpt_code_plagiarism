#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> permutation(N);
    for(int i = 0; i < N; i++) {
        std::cin >> permutation[i];
    }

    int operations = 0;
    for(int i = 0; i < N; i++) {
        if(permutation[i] != i + 1) {
            operations++;
            // Find the index of the current number in the permutation
            int index = std::find(permutation.begin(), permutation.end(), i + 1) - permutation.begin();
            // Reverse the interval [i, index]
            std::reverse(permutation.begin() + i, permutation.begin() + index + 1);
        }
    }

    std::cout << operations << std::endl;

    return 0;
}