#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> notes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> notes[i];
    }

    int min_rooms = 1;
    int current_max = 0;

    for (int i = 1; i < n; i++) {
        if (notes[i] > current_max) {
            min_rooms++;
            current_max = i;
        }
    }

    std::cout << min_rooms << std::endl;

    return 0;
}