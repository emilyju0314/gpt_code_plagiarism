#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    int sum = 0;
    int max_element = 0;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        sum += a[i];
        max_element = std::max(max_element, a[i]);
    }

    if (sum % 2 == 0 && max_element <= sum - max_element) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}