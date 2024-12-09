#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long m, d, w;
        cin >> m >> d >> w;

        long long g = gcd(d-1, w);
        long long max_pairs = min(d, w) - 1;
        long long num_segments = min(d, w) / g;
        long long total_pairs = (m-1) * min(d, w) + min(d, w) * num_segments * (num_segments - 1) / 2;

        cout << total_pairs / g << endl;
    }

    return 0;
}