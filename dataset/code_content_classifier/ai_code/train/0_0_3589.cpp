#include <iostream>

using namespace std;

bool isPossible(int n, int k, int d1, int d2) {
    if(n % 3 != 0) return false;
    
    int a = (k + d1 + d2) / 3;
    int b = a - d1;
    int c = b - d2;
    
    if(a >= 0 && b >= 0 && c >= 0 && a <= n/3 && b <= n/3 && c <= n/3) {
        if((a + b + c) == k && (a <= (n/3 - d1) && b <= (n/3 - d2))) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, k, d1, d2;
        cin >> n >> k >> d1 >> d2;
        
        if(isPossible(n, k, d1, d2)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    
    return 0;
}