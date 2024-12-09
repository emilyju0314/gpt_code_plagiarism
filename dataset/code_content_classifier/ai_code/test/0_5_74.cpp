#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::vector<int> original(n);
    bool possible = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                original[j] = arr[i] + arr[j] - arr[(i+1)%n];
            }
        }

        possible = true;
        for (int j = 0; j < n; j++) {
            if (original[(j+1)%n] + original[j] != arr[j]) {
                possible = false;
                break;
            }
        }

        if (possible) {
            break;
        }
    }

    if (possible) {
        std::cout << "YES\n";
        for (int i = 0; i < n; i++) {
            std::cout << original[i] << " ";
        }
    } else {
        std::cout << "NO";
    }

    return 0;
}