#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t; // number of test cases

    while (t--) {
        int n;
        std::cin >> n; // number of BerLine base stations

        std::vector<int> p(n);
        for (int i = 0; i < n; i++) {
            std::cin >> p[i]; // order in which the base stations are turned on
        }

        std::vector<int> frequencies(n);
        int currFreq = 1;
        std::vector<int> frequencyCount(25, 0);

        for (int i = 0; i < n; i++) {
            frequencies[p[i] - 1] = currFreq;
            frequencyCount[currFreq]++;
            while (frequencyCount[currFreq] > 1) {
                currFreq++;
            }
        }

        for (int i = 0; i < n; i++) {
            std::cout << frequencies[i] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}