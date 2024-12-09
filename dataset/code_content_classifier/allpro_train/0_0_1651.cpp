#include <iostream>

long long countSweetToothChildren(long long n, long long l, long long r, long long k) {
    long long diff = n - r + l - 1;
    
    if(k < l || k > r) {
        if(k == 1) return n;
        else return n - 1;
    } else {
        long long sweetToothCount = (k < r) ? (r - k) : (r - l);
        long long sweetToothPossibilities = (k < r) ? (r - l) + 1 : (r - l);
        long long sweetToothMax = (diff / sweetToothPossibilities) * sweetToothCount;
        return sweetToothMax;
    }
}

int main() {
    long long n, l, r, k;
    std::cin >> n >> l >> r >> k;

    long long result = countSweetToothChildren(n, l, r, k);

    if(result == -1) {
        std::cout << "-1";
    } else {
        std::cout << result;
    }

    return 0;
}