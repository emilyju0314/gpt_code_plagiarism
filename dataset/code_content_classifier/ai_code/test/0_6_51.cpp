#include <iostream>
#include <cmath>

using namespace std;

void solve(int n) {
    long long sum = 0;

    for(long long i = 1; i <= n; i++) {
        sum += i;
        if(sum >= n) {
            if((sum - n) % 2 == 0) {
                long long r = i;
                long long l = (r - sum + n) / 2;
                cout << l << " " << r << endl;
                return;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long n;
        cin >> n;
        solve(n);
    }

    return 0;
}