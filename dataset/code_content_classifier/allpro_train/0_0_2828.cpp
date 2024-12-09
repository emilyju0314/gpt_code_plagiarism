#include <iostream>
#include <string>

int main() {
    int K;
    std::cin >> K;
    
    int count = 1; // starting from the first element in the sequence
    long long num = 7; // the first element in the sequence
    while(num % K != 0) { // loop until we find a multiple of K
        num = num*10 + 7; // generate the next number in the sequence
        count++;

        // check if the next number exceeds the maximum constraint
        if (num > 1000000000) {
            std::cout << "-1" << std::endl;
            return 0;
        }
    }

    std::cout << count << std::endl;

    return 0;
}