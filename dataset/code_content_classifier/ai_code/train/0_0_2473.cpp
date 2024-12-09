#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_prime(int n) {
    if(n <= 1) {
        return false;
    }
    for(int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

bool is_palindromic(int n) {
    string s = to_string(n);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

int main() {
    int p, q;
    cin >> p >> q;
    
    int max_n = 0;
    for(int n = 1; ; n++) {
        int primes = 0, palindromic = 0;
        for(int i = 2; i <= n; i++) {
            if(is_prime(i)) {
                primes++;
            }
            if(is_palindromic(i)) {
                palindromic++;
            }
        }
        
        if(primes <= p * palindromic / q) {
            max_n = n;
        } else {
            break;
        }
    }
    
    if(max_n == 0) {
        cout << "Palindromic tree is better than splay tree" << endl;
    } else {
        cout << max_n << endl;
    }
    
    return 0;
}