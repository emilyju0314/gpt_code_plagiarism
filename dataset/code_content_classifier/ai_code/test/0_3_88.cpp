#include <iostream>
#include <vector>
#include <algorithm>

bool isPossibleToSplitSequence(std::vector<int>& sequence) {
    int n = sequence.size();
    
    std::vector<int> lis(n, 1);
    int maxXOR = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (sequence[i] > sequence[j]) {
                lis[i] = std::max(lis[i], lis[j] + 1);
            }
        }
        maxXOR ^= lis[i];
    }

    if (maxXOR == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> sequence(n);
        
        for (int i = 0; i < n; i++) {
            std::cin >> sequence[i];
        }

        if (isPossibleToSplitSequence(sequence)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}