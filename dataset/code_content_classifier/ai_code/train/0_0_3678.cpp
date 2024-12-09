#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> letters(n);
    for (int i = 0; i < n; i++) {
        std::cin >> letters[i];
    }

    int operations = 0;
    int current = 0;
    for (int i = 0; i < n; i++) {
        if (letters[i] == 1) {
            operations++;
            current = i;
            while (current < n-1 && letters[current+1] == 1) {
                current++;
            }
            operations++;
        }
    }

    std::cout << operations << std::endl;

    return 0;
}