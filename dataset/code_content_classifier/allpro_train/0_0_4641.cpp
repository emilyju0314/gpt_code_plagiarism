#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if(num <= 1) {
        return false;
    }
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) {
            return false; // Not a prime number
        }
    }
    return true; // Prime number
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> levels(n+1, 0);
    
    for(int i = 0; i < n; i++) {
        int p, c, l;
        cin >> p >> c >> l;
        
        if(p >= k) {
            cout << 1 << endl;
            return 0; // Vova can build the deck with just one card
        }
        
        for(int j = 1; j <= n; j++) {
            if(levels[j] != 0 && !isPrime(c + levels[j])) {
                levels[j] += c;
                if(levels[j] >= k) {
                    cout << j << endl;
                    return 0; // Minimum level needed to build the deck
                }
            }
        }
        
        if(l == 1) {
            levels[l] = c;
            if(levels[l] >= k) {
                cout << l << endl;
                return 0; // Minimum level needed to build the deck
            }
        }
    }
    
    cout << -1 << endl; // Vova can't build the deck with required power
    
    return 0;
}