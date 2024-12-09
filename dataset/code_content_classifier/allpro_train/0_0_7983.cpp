#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

uint64_t multiply_powers_of_2(uint64_t a, uint64_t b) {
    if (a == 1 || b == 1) return a * b;
    
    int n = 0;
    uint64_t power = 1;
    while ((1ULL << (1ULL << n)) <= max(a, b)) {
        power = 1ULL << (1ULL << n);
        n++;
    }
    
    if (a >= power && b >= power) {
        return multiply_powers_of_2(power * 3 / 2, multiply_powers_of_2(a / power, b / power));
    } else if (a >= power) {
        return multiply_powers_of_2(a / power, b) * power;
    } else {
        return multiply_powers_of_2(a, b / power) * power;
    }
}

uint64_t multiply(uint64_t a, uint64_t b) {
    uint64_t ans = 0;
    
    for (int p1 = 0; p1 < 64; p1++) {
        if (a & (1LL << p1)) {
            for (int p2 = 0; p2 < 64; p2++) {
                if (b & (1LL << p2)) {
                    ans = ans ^ multiply_powers_of_2(1ULL << p1, 1ULL << p2);
                }
            }
        }
    }
    
    return ans;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        uint64_t a, b;
        cin >> a >> b;
        
        uint64_t x = 0;
        while (multiply(a, x) != b && x < (1ULL << 64)) {
            x++;
        }
        
        if (multiply(a, x) == b) {
            cout << x << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}