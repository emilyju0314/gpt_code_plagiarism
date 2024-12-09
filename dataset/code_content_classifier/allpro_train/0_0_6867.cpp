#include <iostream>
#include <vector>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }

    std::set<int> distinctValues;
    for (int i = 0; i < n; i++) {
        int current = 0;
        for (int j = i; j < n; j++) {
            current |= sequence[j];
            distinctValues.insert(current);
        }
    }

    std::cout << distinctValues.size() << std::endl;

    return 0;
}