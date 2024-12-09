#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> seats(n);
    for (int i = 0; i < n; i++) {
        std::cin >> seats[i];
    }

    int total_seats = 0;
    for (int i = 0; i < n; i++) {
        total_seats += seats[i];
    }

    for (int i = 0; i < n; i++) {
        if (seats[i] * 2 > seats[0] && total_seats - seats[i] > seats[i]) {
            std::cout << "2\n1 " << i+1 << std::endl;
            return 0;
        }
    }

    std::cout << "0" << std::endl;

    return 0;
}