#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }

    int start = -1, end = -1;
    for (int i = 0; i < n-1; i++) {
        if (sequence[i] > sequence[i+1]) {
            start = i;
            end = i+1;
            break;
        }
    }

    if (start == -1) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << 3 << std::endl;
        std::cout << start+1 << " " << end+1 << " " << end+2 << std::endl;
    }

    return 0;
}