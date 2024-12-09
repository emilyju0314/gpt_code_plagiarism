#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

long long pow_mod(long long base, long long exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, m, k, r, c;
    cin >> n >> m >> k >> r >> c;
    
    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    
    long long total_combinations = 1;
    for(int i = 0; i < r*c; i++) {
        total_combinations = (total_combinations * k) % MOD;
    }
    
    long long same_pattern_combinations = 0;
    if((ax - bx) % r == 0 && (ay - by) % c == 0) {
        long long repetitions_x = (ax - bx) / r;
        long long repetitions_y = (ay - by) / c;
        
        same_pattern_combinations = pow_mod(total_combinations, repetitions_x * repetitions_y);
    }
    
    cout << same_pattern_combinations << endl;
    
    return 0;
}