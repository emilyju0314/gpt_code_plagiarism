#include <iostream>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        long long a, m;
        cin >> a >> m;

        long long g = gcd(a, m);
        m /= g;

        long long cnt = 1;
        for(long long i=2; i*i<=m; i++) {
            if(m % i == 0) {
                cnt *= i;
                while(m % i == 0)
                    m /= i;
            }
        }
        if(m > 1) cnt *= m;

        cout << g*cnt << endl;
    }

    return 0;
}