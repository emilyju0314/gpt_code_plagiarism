#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> p(n);
    for(int i = 0; i < n; i++) {
        std::cin >> p[i];
    }

    int inversionCount = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(p[i] > p[j]) {
                inversionCount++;
            }
        }
    }

    int minInversionCount = inversionCount;
    for(int i = 0; i < n; i++) {
        int currentInversionCount = inversionCount;
        if(p[i] > 0) {
            currentInversionCount -= i;
        } else {
            currentInversionCount += i;
        }
        minInversionCount = std::min(minInversionCount, currentInversionCount);
    }

    std::cout << minInversionCount << std::endl;

    return 0;
}