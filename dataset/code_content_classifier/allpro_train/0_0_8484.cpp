#include <iostream>
#include <unordered_set>

int main() {
    int n, m, x, y;
    std::cin >> n >> m >> x >> y;

    std::unordered_set<int> faulty_modules;
    for (int i = 0; i < x; ++i) {
        int module;
        std::cin >> module;
        faulty_modules.insert(module);
    }

    std::unordered_set<int> working_modules;
    for (int i = 0; i < y; ++i) {
        int module;
        std::cin >> module;
        working_modules.insert(module);
    }

    int faulty_count = 0;
    int working_count = 0;

    for (int i = 1; i <= n; ++i) {
        if (faulty_modules.count(i) > 0 && working_modules.count(i) > 0) {
            ++faulty_count;
            ++working_count;
        } else if (faulty_modules.count(i) > 0) {
            ++faulty_count;
        } else if (working_modules.count(i) > 0) {
            ++working_count;
        }
    }

    std::cout << working_count << " " << faulty_count << std::endl;

    return 0;
}