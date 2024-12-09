#include <iostream>
#include <vector>

void printSubset(int num, int n) {
    std::vector<int> subset;
    for (int i = 0; i < n; i++) {
        if ((num & (1 << i)) != 0) {
            subset.push_back(i);
        }
    }
    std::cout << num << ":";
    for (int i = 0; i < subset.size(); i++) {
        std::cout << " " << subset[i];
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < (1 << n); i++) {
        printSubset(i, n);
    }

    return 0;
}