#include <iostream>

int main() {
    long long K;
    std::cin >> K;

    std::string s = "FESTIVAL";
    int numRepeat = 8;

    std::string result = "";
    while(K > 0) {
        long long count = K % numRepeat;
        for(int i = 0; i < count; i++) {
            result += s[i];
        }
        K /= numRepeat;
    }

    std::cout << result;

    return 0;
}