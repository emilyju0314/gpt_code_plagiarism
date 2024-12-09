#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::string clowns, acrobats;
    std::cin >> clowns >> acrobats;

    std::vector<int> first_performance;
    for (int i = 0; i < n; ++i) {
        if (clowns[i] == '1') {
            first_performance.push_back(i + 1);
        }
    }

    std::vector<int> second_performance;
    for (int i = 0; i < n; ++i) {
        if (acrobats[i] == '1') {
            second_performance.push_back(i + 1);
        }
    }

    bool valid = false;
    for (int i = 0; i < first_performance.size(); ++i) {
        int clown_count = i + 1;
        int acrobat_count = first_performance.size() - clown_count;
        if (acrobat_count <= 0) {
            break;
        }

        for (int j = 0; j < second_performance.size(); ++j) {
            if (second_performance[j] == first_performance[i]) {
                continue;
            }

            if (acrobat_count == clown_count) {
                std::cout << first_performance[i] << " " << second_performance[j] << " ";
                for (int k = 0; k < i; ++k) {
                    std::cout << first_performance[k] << " ";
                }
                for (int k = 0; k < j; ++k) {
                    std::cout << second_performance[k] << " ";
                }
                valid = true;
                break;
            }
        }
        if (valid) {
            break;
        }
    }

    if (!valid) {
        std::cout << -1;
    }

    return 0;
}