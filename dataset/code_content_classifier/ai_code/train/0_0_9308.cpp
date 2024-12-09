#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    int q;
    std::cin >> q;

    std::unordered_map<std::string, std::string> handleMap;

    for (int i = 0; i < q; i++) {
        std::string oldHandle, newHandle;
        std::cin >> oldHandle >> newHandle;

        handleMap[oldHandle] = newHandle;
    }

    std::cout << handleMap.size() << std::endl;

    for (const auto& entry : handleMap) {
        std::cout << entry.first << " " << entry.second << std::endl;
    }

    return 0;
}