#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> kirill_values(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> kirill_values[i];
    }

    std::sort(kirill_values.begin(), kirill_values.end());

    int min_equal_measurements = n;
    std::cout << min_equal_measurements << std::endl;

    int mid_value = kirill_values[n / 2];
    for (int i = 0; i < n; ++i) {
        if (kirill_values[i] == mid_value || kirill_values[i] == mid_value + 1) {
            std::cout << kirill_values[i] << " ";
        } else if (kirill_values[i] == mid_value - 1) {
            std::cout << mid_value << " ";
        }
    }

    return 0;
}