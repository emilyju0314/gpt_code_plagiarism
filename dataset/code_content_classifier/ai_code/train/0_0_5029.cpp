#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> odd, even;

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (a[i] % 2 == 0) {
            even.push_back(a[i]);
        } else {
            odd.push_back(a[i]);
        }
    }

    for (int i = 0; i < odd.size(); i++) {
        std::cout << odd[i] << " ";
    }
    for (int i = 0; i < even.size(); i++) {
        std::cout << even[i] << " ";
    }

    return 0;
}