#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string text;
    std::getline(std::cin, text);

    std::vector<int> arr;
    int prev = 0;
    for(char c : text) {
        int ascii = int(c);
        int reverse_prev = 0;
        for(int i = 0; i < 8; i++) {
            reverse_prev = reverse_prev << 1;
            reverse_prev |= prev & 1;
            prev = prev >> 1;
        }

        int result = (reverse_prev - ascii) % 256;
        if(result < 0) result += 256;

        arr.push_back(result);
        prev = reverse_prev;
    }

    for(int num : arr) {
        std::cout << num << std::endl;
    }

    return 0;
}