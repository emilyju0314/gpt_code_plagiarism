#include <iostream>
#include <cmath>

#define MOD 1000000007

typedef long long ll;

ll sumOfRange(ll l, ll r) {
    ll sum = 0;
    ll power = 0;
    ll start = 1;
    ll end = 2;
    while(end < l) {
        power++;
        if(power % 2 == 1) {
            start = end + 1;
            end = start + pow(2, power) - 1;
        } else {
            start = end + 1;
            end = start + pow(2, power) - 1;
        }
    }
    while(start <= r) {
        if(start <= l && end >= r) {
            for(ll i = l; i <= r; i++) {
                sum = (sum + start + i - l) % MOD;
            }
            break;
        }
        if(start >= l && end <= r) {
            for(ll i = start; i <= end; i++) {
                sum = (sum + i) % MOD;
            }
        } else if(start <= l && end > l) {
            for(ll i = l; i <= end; i++) {
                sum = (sum + start + i - l) % MOD;
            }
        } else if(start < r && end >= r) {
            for(ll i = start; i <= r; i++) {
                sum = (sum + i) % MOD;
            }
        }
        power++;
        if(power % 2 == 1) {
            start = end + 1;
            end = start + pow(2, power) - 1;
        } else {
            start = end + 1;
            end = start + pow(2, power) - 1;
        }
    }
    return sum;
}

int main() {
    ll l, r;
    std::cin >> l >> r;
    std::cout << sumOfRange(l, r) << std::endl;
    return 0;
}