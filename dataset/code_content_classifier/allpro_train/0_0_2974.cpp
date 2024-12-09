#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    long long sum = 0, min_num_of_integers = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    for (int i = 0; ; i++) {
        if (sum >= (1 << i) - 1) {
            continue;
        } else {
            min_num_of_integers = (1 << i) - 1 - sum;
            break;
        }
    }

    std::cout << min_num_of_integers << std::endl;

    return 0;
}