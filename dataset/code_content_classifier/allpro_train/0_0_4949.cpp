#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        long long n, g, b;
        cin >> n >> g >> b;

        long long full_cycles = ceil((double)n / (double)(g + b)) - 1;
        long long ans = max(n, (g + b) * full_cycles + g + max(0LL, (n - (g + b) * full_cycles)));
        
        cout << ans << endl;
    }

    return 0;
}