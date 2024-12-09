#include <iostream>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long ans = 0;
    
    if(k == 1 || n % 2 == k % 2) {
        ans = n;
    } else {
        ans = n | (long long)1;
    }

    cout << ans << endl;

    return 0;
}