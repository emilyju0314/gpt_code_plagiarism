#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
       return a;
    return gcd(b, a % b);
}

long long c(int l, int r) {
    long long res = 0;
    for (int i = l; i <= r; i++) {
        for (int j = i; j <= r; j++) {
            if (gcd(i, j) >= l) {
                res++;
            }
        }
    }
    return res;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        long long sum = 0;
        int x = n / k;
        int rem = n % k;
        sum += rem * x * (x + 1) / 2; // using formula for sum of first x natural numbers
        
        sum += (k - rem) * (x - 1) * x / 2;
        
        cout << sum << endl;
    }

    return 0;
}