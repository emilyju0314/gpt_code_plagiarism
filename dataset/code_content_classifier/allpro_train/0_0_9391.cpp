#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
vector<int> a;
set<int> b;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

bool is_good_prime(int p) {
    for(int bad_prime : b) {
        if (p % bad_prime == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < m; i++) {
        int prime;
        cin >> prime;
        b.insert(prime);
    }
    
    int max_beauty = 0;
    
    for(int i = 0; i < n; i++) {
        int current_gcd = a[i];
        int current_beauty = 0;
        
        for(int j = i; j >= 0; j--) {
            current_gcd = gcd(current_gcd, a[j]);
            if(current_gcd == 1) {
                current_beauty += 1;
            } else if(is_good_prime(current_gcd)) {
                current_beauty += current_gcd;
            } else {
                current_beauty -= current_gcd;
            }
            
            max_beauty = max(max_beauty, current_beauty);
        }
    }
    
    cout << max_beauty << endl;
    
    return 0;
}