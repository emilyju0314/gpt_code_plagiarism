#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::unordered_set<int> blocks;
    for (int i = 0; i < n; ++i) {
        int block;
        std::cin >> block;
        blocks.insert(block);
    }

    std::vector<int> output;

    // Find the missing blocks that can be used to form the required set Y
    for (int i = 1; i <= 1000000; ++i) {
        if (output.size() == 1000000 - n) {
            break;
        }
        if (blocks.find(i) == blocks.end()) {
            output.push_back(i);
        }
    }

    std::cout << output.size() << std::endl;
    for (int i : output) {
        std::cout << i << " ";
    }

    return 0;
}