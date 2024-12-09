#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;
        
        long long count = 0;
        
        for (int i = 1; i * i * i <= n; i++) {
            count++;
        }
        
        for (int i = 1; i * i <= n; i++) {
            if (i * i * i <= n) {
                count--;
            }
        }
        
        cout << count + floor(sqrt(n)) << endl;
    }
    
    return 0;
}