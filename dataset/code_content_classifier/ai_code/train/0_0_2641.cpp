#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> chemicals(n);
    for(int i = 0; i < n; i++) {
        std::cin >> chemicals[i];
    }

    int count = 0;
    while(true) {
        bool allEqual = true;
        for(int i = 1; i < n; i++) {
            if(chemicals[i] != chemicals[i-1]) {
                allEqual = false;
                break;
            }
        }
        if(allEqual) break;

        int minVol = *std::min_element(chemicals.begin(), chemicals.end());
        int operations = 0;
        for(int i = 0; i < n; i++) {
            if(chemicals[i] % 2 == 0) {
                operations += (chemicals[i] - minVol) / 2;
            } else {
                operations += (chemicals[i] - minVol + 1) / 2;
            }
        }

        count += operations;
        for(int i = 0; i < n; i++) {
            chemicals[i] = minVol;
        }
    }

    std::cout << count << std::endl;

    return 0;
}