#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> concentrations(k);
    for(int i = 0; i < k; i++) {
        std::cin >> concentrations[i];
    }

    std::sort(concentrations.begin(), concentrations.end());

    int minLiters = -1;

    for(int i = 0; i < k; i++) {
        int target = n;
        int liters = 0;

        for(int j = i; j < k; j++) {
            target -= concentrations[j];
            liters++;
            if(target <= 0) {
                minLiters = (minLiters == -1) ? liters : std::min(minLiters, liters);
                break;
            }
        }
    }

    std::cout << minLiters << std::endl;

    return 0;
}