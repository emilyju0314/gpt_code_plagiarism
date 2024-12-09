#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> permutation(n);
    for(int i = 0; i < n; i++) {
        std::cin >> permutation[i];
    }

    int result = 0;
    for(int i = 0; i < n; i++) {
        int count_m = 0;
        for(int j = i; j < n; j++) {
            if(permutation[j] == m) {
                count_m++;
            }
            if(2*count_m > (j-i+1)) {
                result++;
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}