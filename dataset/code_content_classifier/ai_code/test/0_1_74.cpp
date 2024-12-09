#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> output(n);
    for (int i = 0; i < n; i++) {
        std::cin >> output[i];
    }

    std::vector<int> input(n);
    for (int i = 0; i < n; i++) {
        input[i] = output[0];
    }

    for (int i = 1; i < n; i++) {
        std::vector<int> temp = input;
        bool found = false;

        for (int j = 0; j < n; j++) {
            input[j] = output[i] - temp[j];

            if (j > 0 && input[j] <= input[j - 1]) {
                found = false;
                break;
            } else {
                found = true;
            }
        }

        if (!found) {
            input = temp;
        } else {
            break;
        }
    }

    if (std::is_sorted(input.begin(), input.end()) && accumulate(input.begin(), input.end(), 0) == accumulate(output.begin(), output.end(), 0)) {
        std::cout << "YES" << std::endl;
        for (int i = 0; i < n; i++) {
            std::cout << input[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}