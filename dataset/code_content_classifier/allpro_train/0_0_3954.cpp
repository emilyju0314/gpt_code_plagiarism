#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    long long total_distance = 0;
    for (int u = 1; u < n; u++) {
        for (int v = u + 1; v <= n; v++) {
            total_distance += gcd(u, v);
        }
    }

    cout << total_distance << endl;

    return 0;
}