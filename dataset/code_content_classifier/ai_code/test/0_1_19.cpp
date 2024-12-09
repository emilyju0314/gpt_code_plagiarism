#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::vector<int> segments(n);
        for(int i = 0; i < n; i++) {
            std::cin >> segments[i];
        }

        int coverage = segments[0];
        int end = segments[0];

        for(int i = 1; i < n; i++) {
            if(end < segments[i]) {
                coverage += segments[i] - end;
            }

            end = std::max(end, segments[i]);
        }

        std::cout << coverage << std::endl;
    }

    return 0;
}