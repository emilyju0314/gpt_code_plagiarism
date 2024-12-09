#include <iostream>

long long totalDegreeOfBeauty(long long n) {
    if(n == 1) {
        return 5;
    } else {
        return totalDegreeOfBeauty(n-1) + (4*n-1)*(4*n-2);
    }
}

int main() {
    long long m;
    std::cin >> m;

    long long result = totalDegreeOfBeauty(m);
    std::cout << result << std::endl;

    return 0;
}