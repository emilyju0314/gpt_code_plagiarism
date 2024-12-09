#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::string seating;
    std::cin >> seating;

    // Check if the seating is maximal
    bool isMaximal = true;
    for (int i = 0; i < n; ++i) {
        if (seating[i] == '1') {
            if ((i - 1 >= 0 && seating[i-1] == '1') || (i + 1 < n && seating[i+1] == '1')) {
                isMaximal = false;
                break;
            }
        }
    }

    if (isMaximal) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }

    return 0;
}