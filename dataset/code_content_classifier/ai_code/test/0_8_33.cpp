#include <iostream>
#include <vector>
#include <set>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::set<int> possible_values;
    possible_values.insert(0);
    for(int i = 0; i < n; i++) {
        std::set<int> new_possible_values = possible_values;
        for(auto val : possible_values) {
            new_possible_values.insert(val ^ a[i]);
        }
        possible_values = new_possible_values;
    }

    std::cout << possible_values.size() << std::endl;
    for(auto val : possible_values) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}