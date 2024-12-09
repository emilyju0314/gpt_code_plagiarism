#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long n, k;
        cin >> n >> k;
        
        long long steps = 0;
        while(n > 0) {
            if(n % k == 0) {
                n /= k;
                steps++;
            } else {
                long long rem = n % k;
                steps += rem;
                n -= rem;
            }
        }
        
        cout << steps << endl;
    }

    return 0;
}