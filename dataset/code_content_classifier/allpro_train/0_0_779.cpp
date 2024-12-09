#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
    int n;
    std::cin >> n;

    std::map<std::string, int> list_a, list_b;

    for (int i = 0; i < n; ++i) {
        std::string size_a, size_b;
        std::cin >> size_a >> size_b;
        list_a[size_a]++;
        list_b[size_b]++;
    }

    int changes = 0;
    for (auto it = list_b.begin(); it != list_b.end(); ++it) {
        std::string size = it->first;
        int count_b = it->second;

        if (list_a.find(size) == list_a.end()) {
            changes += count_b;
        } else {
            changes += std::max(0, count_b - list_a[size]);
        }
    }

    std::cout << changes << std::endl;

    return 0;
}