#include <iostream>
#include <vector>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::set<int> x_values;
    x_values.insert(0);

    for (int i = 0; i < n; i++) {
        std::set<int> new_values;
        for (int x : x_values) {
            new_values.insert(x ^ a[i]);
        }
        for (int x : new_values) {
            x_values.insert(x);
        }
    }

    std::cout << x_values.size() << std::endl;
    for (int x : x_values) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}