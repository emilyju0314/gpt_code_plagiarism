#include <iostream>
#include <vector>

void moveDisk(int n, int source, int destination) {
    std::cout << n << " " << source << " " << destination << std::endl;
}

void solveTowerOfHanoi(int n, int source, int destination, int intermediate) {
    if (n == 1) {
        moveDisk(1, source, destination);
    } else {
        solveTowerOfHanoi(n-1, source, intermediate, destination);
        moveDisk(n, source, destination);
        solveTowerOfHanoi(n-1, intermediate, destination, source);
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> diameters(n);
    for (int i = 0; i < n; i++) {
        std::cin >> diameters[i];
    }

    std::vector<int> uniqueDiameters;
    for (int i = 0; i < n; i++) {
        if (i == 0 || diameters[i] != diameters[i-1]) {
            uniqueDiameters.push_back(diameters[i]);
        }
    }

    int m = uniqueDiameters.size();

    std::cout << (1 << m) - 1 << std::endl;

    solveTowerOfHanoi(n, 1, 3, 2);

    return 0;
}