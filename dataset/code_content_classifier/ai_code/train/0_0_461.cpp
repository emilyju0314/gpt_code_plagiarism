#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> esthetic_appeals(n);
    for (int i = 0; i < n; i++) {
        std::cin >> esthetic_appeals[i];
    }

    std::vector<int> idx_to_remove;
    long long sum = 0;

    // Find the first two trees with the same esthetic appeal
    int first_occurrence = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (esthetic_appeals[i] == esthetic_appeals[j]) {
                first_occurrence = i;
                break;
            }
        }
        if (first_occurrence != -1) {
            break;
        }
    }

    // Calculate the sum of esthetic appeal and trees to remove
    for (int i = 0; i < n; i++) {
        sum += esthetic_appeals[i];
        if (i == first_occurrence) {
            continue;
        } else {
            idx_to_remove.push_back(i + 1);
        }
    }

    std::cout << sum << " " << idx_to_remove.size() << std::endl;
    for (int idx : idx_to_remove) {
        std::cout << idx << " ";
    }

    return 0;
}