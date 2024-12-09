#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::unordered_map<int, int> last_occurrence;
    for (int i = 0; i < n; i++) {
        last_occurrence[a[i]] = i;
    }

    std::vector<int> unique_elements;
    for (const auto& entry : last_occurrence) {
        unique_elements.push_back(entry.first);
    }

    std::cout << unique_elements.size() << std::endl;
    for (int i = 0; i < unique_elements.size(); i++) {
        std::cout << unique_elements[i];
        if (i < unique_elements.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}