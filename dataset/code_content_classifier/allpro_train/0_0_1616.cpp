#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> weights(2*n);
    for(int i = 0; i < 2*n; i++) {
        std::cin >> weights[i];
    }

    std::sort(weights.begin(), weights.end());

    int min_instability = INT_MAX;

    for(int i = 0; i < 2*n; i++) {
        for(int j = i+1; j < 2*n; j++) {
            int instability = 0;
            int idx1 = 0, idx2 = n;

            for(int k = 0; k < 2*n; k++) {
                if(k == i || k == j) continue;

                if(idx1 < i || (idx1 == i && idx2 == j)) {
                    instability += abs(weights[k] - weights[idx1]);
                    idx1++;
                } else {
                    instability += abs(weights[k] - weights[idx2]);
                    idx2++;
                }
            }

            min_instability = std::min(min_instability, instability);
        }
    }

    std::cout << min_instability << std::endl;

    return 0;
}