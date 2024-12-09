#include <iostream>
#include <algorithm>

using namespace std;

long long countTriangles(int a, int b, int c, int l) {
    long long total = 0;

    for(int i = 0; i <= l; i++) {
        for(int j = 0; j <= l; j++) {
            int remaining = l - i - j;
            if(remaining < 0) break;
            total += (long long)(a + i + 1) * (b + j + 1) * max(0, c + remaining + 1);
        }
    }

    return total;
}

int main() {
    int a, b, c, l;
    cin >> a >> b >> c >> l;

    long long ways = countTriangles(a, b, c, l);
    cout << ways << "\n";

    return 0;
}