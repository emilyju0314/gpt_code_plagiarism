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

    int cost = 0;
    for(int i = 0; i < n; i++) {
        if(p[i] == i+1) {
            // Current element is in the correct position
            for(int j = i+1; j < n; j++) {
                if(p[j] != j+1) {
                    // Find the element that should be at this position
                    int index = -1;
                    for(int k = j+1; k < n; k++) {
                        if(p[k] == j+1) {
                            index = k;
                            break;
                        }
                    }
                    std::swap(p[j], p[index]);
                    cost += (p[j] + p[index]) * std::abs(j - index);
                }
            }
        }
    }

    std::cout << cost << std::endl;

    return 0;
}