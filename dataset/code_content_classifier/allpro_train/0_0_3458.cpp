#include <iostream>
#include <algorithm>

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int N;
    std::cin >> N;
    
    int ratios[N];
    for (int i = 0; i < N; i++) {
        std::cin >> ratios[i];
    }
    
    int result = ratios[0];
    for (int i = 1; i < N; i++) {
        result = gcd(result, ratios[i]);
    }
    
    std::cout << result << std::endl;
    
    return 0;
}