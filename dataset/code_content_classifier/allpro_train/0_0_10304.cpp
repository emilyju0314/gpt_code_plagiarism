#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::unordered_set<int> values_set;
    for (int i = 0; i < n; ++i) {
        int val;
        std::cin >> val;
        values_set.insert(val);
    }

    int m;
    std::cin >> m;

    for (int i = 0; i < m; ++i) {
        int val;
        std::cin >> val;
        values_set.insert(val);
    }

    std::cout << values_set.size() << std::endl;

    return 0;
}