#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> grades(n);
    for (int i = 0; i < n; i++) {
        std::cin >> grades[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += grades[i];
    }

    int redo_count = 0;
    while (sum < n * 4.5) {
        sum += 5;
        redo_count++;
    }

    std::cout << redo_count << std::endl;

    return 0;
}