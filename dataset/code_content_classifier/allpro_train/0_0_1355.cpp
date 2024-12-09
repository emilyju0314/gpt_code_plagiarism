#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> A(n);
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    // Check if it is possible to split the array A
    bool possible = false;
    for (int i = 0; i < n; i++) {
        if (A[i] != 0) {
            possible = true;
            break;
        }
    }

    if (!possible) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
        int k = 0;
        
        std::vector<std::pair<int, int>> splits;
        for (int i = 0; i < n; i++) {
            if (A[i] != 0) {
                int j = i;
                while (j < n && A[j] != 0) {
                    j++;
                }
                splits.push_back({i+1, j});
                i = j;
                k++;
            }
        }

        std::cout << k << std::endl;
        for (auto split : splits) {
            std::cout << split.first << " " << split.second << std::endl;
        }
    }

    return 0;
}