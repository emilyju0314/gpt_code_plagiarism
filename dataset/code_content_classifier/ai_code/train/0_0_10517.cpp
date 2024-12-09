#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;
    int n;
    cin >> n;

    vector<long long> fib(n);
    fib[0] = x;
    fib[1] = y;

    for(int i = 2; i < n; i++) {
        fib[i] = (fib[i-1] - fib[i-2]) % 1000000007;
    }

    cout << (fib[n-1] < 0 ? fib[n-1] + 1000000007 : fib[n-1]) << endl;

    return 0;
}