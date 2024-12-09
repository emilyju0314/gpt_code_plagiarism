#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;

    int pivotPos = s.find('^');
    long long leftWeight = 0, rightWeight = 0;

    for(int i = 0; i < s.length(); i++) {
        if(s[i] >= '1' && s[i] <= '9') {
            if(i < pivotPos) {
                leftWeight += s[i] - '0';
            } else if(i > pivotPos) {
                rightWeight += s[i] - '0';
            }
        }
    }

    if(leftWeight == rightWeight) {
        std::cout << "balance" << std::endl;
    } else if(leftWeight < rightWeight) {
        std::cout << "right" << std::endl;
    } else {
        std::cout << "left" << std::endl;
    }

    return 0;
}