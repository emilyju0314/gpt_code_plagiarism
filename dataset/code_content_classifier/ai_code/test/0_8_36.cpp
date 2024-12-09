#include <iostream>
#include <vector>

bool isComposite(int num) {
    if(num <= 1) {
        return false;
    }
    for(int i = 2; i < num; i++) {
        if(num % i == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        int n;
        std::cin >> n;

        std::vector<int> arr(n);
        
        for(int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }

        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
        }

        if(isComposite(sum)) {
            std::cout << n << std::endl;
            for(int i = 0; i < n; i++) {
                std::cout << i+1 << " ";
            }
            std::cout << std::endl;
        } else {
            int compositeSubsetSize = 2;
            std::cout << compositeSubsetSize << std::endl;
            std::cout << "1 2" << std::endl;
        }
        
    }

    return 0;
}