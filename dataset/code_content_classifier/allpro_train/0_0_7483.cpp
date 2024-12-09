#include <iostream>
#include <string>
#include <algorithm>

bool isWavyNumber(int num) {
    std::string numStr = std::to_string(num);
    
    for (int i = 1; i < numStr.length() - 1; i++) {
        if ((numStr[i] < numStr[i - 1] && numStr[i] < numStr[i + 1]) || 
            (numStr[i] > numStr[i - 1] && numStr[i] > numStr[i + 1])) {
            continue;
        } else {
            return false;
        }
    }
    
    return true;
}

int main() {
    long long n, k;
    std::cin >> n >> k;
    
    long long count = 0;
    long long ans = -1;

    for (long long r = 1; r <= 10100000; r++) { // Loop up to maximum 1014 divisible wavy number
        if (r % n == 0 && isWavyNumber(r)) {
            count++;
            if (count == k) {
                ans = r;
                break;
            }
        }
    }
    
    std::cout << ans << std::endl;

    return 0;
}