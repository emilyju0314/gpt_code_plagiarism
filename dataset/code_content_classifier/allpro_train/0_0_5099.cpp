#include <iostream>
#include <vector>

void findFoldingDirection(int n, int i, int j) {
    std::vector<int> layers;
    for (int k = 1; k <= i; ++k) {
        layers.push_back(k);
    }

    std::vector<int> parts;
    for (int k = 1; k <= 2 * n; ++k) {
        parts.push_back(k);
    }

    for (int k = 0; k < n; ++k) {
        std::vector<int> nextParts;

        for (int idx = 0; idx < layers.size(); idx += 2) {
            int left = parts[idx];
            int right = parts[idx + 1];
            if (i == left) {
                i = right;
            } else if (i == right) {
                i = left;
            }

            if (j % 2 == 1) {
                nextParts.push_back(left);
            } else {
                nextParts.push_back(right);
            }
        }

        parts.clear();
        for (int p : nextParts) {
            parts.push_back(p);
        }

        j = (j + 1) / 2;
    }

    std::string sequence;
    for (int p : parts) {
        if (i == p) {
            sequence += 'L';
        } else {
            sequence += 'R';
        }
    }

    std::cout << sequence << std::endl;
}

int main() {
    int n, i, j;
    while (std::cin >> n >> i >> j) {
        if (n == 0 && i == 0 && j == 0) {
            break;
        }

        findFoldingDirection(n, i, j);
    }

    return 0;
}