#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> temps(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> temps[i];
    }

    if(temps.size() == 2) {
        std::cout << temps[1] << std::endl;
    } else {
        int diff = temps[1] - temps[0];
        bool isAP = true;

        for(int i = 2; i < n; ++i) {
            if(temps[i] - temps[i-1] != diff) {
                isAP = false;
                break;
            }
        }

        if(isAP) {
            std::cout << temps[n-1] + diff << std::endl;
        } else {
            std::cout << temps[n-1] << std::endl;
        }
    }

    return 0;
}