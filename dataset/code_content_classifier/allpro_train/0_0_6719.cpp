#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int k;
    cin >> k;

    long long ans = 0;

    for(int i = 0; i < k; i++) {
        ans += 1 + 6 * i;
    }

    cout << ans << endl;

    return 0;
}