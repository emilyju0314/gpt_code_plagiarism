#include <iostream>
#include <vector>
#include <algorithm>

int findStepsToAllZeros(const std::vector<int>& array, int d) {
    int n = array.size();
    std::vector<int> countOnes(n, 0);
    int steps = 0;

    for (int i = 0; i < n; ++i) {
        countOnes[i] = array[i];
        if (i > 0) countOnes[i] += countOnes[i-1];
    }

    if (countOnes[n-1] == 0) return 0;

    while (steps < n) {
        if (countOnes[n-1] == 0) {
            return steps;
        }
        for (int i = 0; i < n; ++i) {
            int new_value = array[i] & array[(i - d + n) % n];
            if (new_value != array[i]) {
                array[i] = new_value;
                countOnes[n-1] -= 1;
            }
        }
        steps++;
    }

    return -1;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, d;
        std::cin >> n >> d;
        std::vector<int> array(n);
        
        for (int i = 0; i < n; ++i) {
            std::cin >> array[i];
        }

        int steps = findStepsToAllZeros(array, d);
        std::cout << steps << std::endl;
    }

    return 0;
}