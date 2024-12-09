#include <iostream>
#include <string>
#include <algorithm>

bool isValidBusNumber(const std::string& num) {
    if (num[0] == '0') {
        return false;
    }
    
    for (char c : num) {
        if (std::count(num.begin(), num.end(), c) > std::count(num.begin(), num.end(), c - '0' + '5')) {
            return false;
        }
    }
    
    return true;
}

int main() {
    std::string n;
    std::cin >> n;
    
    int count = 0;
    std::sort(n.begin(), n.end());
    
    do {
        if (isValidBusNumber(n)) {
            count++;
        }
    } while(std::next_permutation(n.begin(), n.end()));
    
    std::cout << count << std::endl;
    
    return 0;
}