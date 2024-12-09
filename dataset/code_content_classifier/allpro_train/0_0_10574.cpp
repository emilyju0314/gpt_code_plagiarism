#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long ans = 0;
    long long min_val = min(a, min(b, c));
    
    ans += min_val * 2;
    
    // if there are still remaining strings of 'a' and 'b', we can add one more good string
    if (a - min_val > 0) {
        ans += 1;
        a -= min_val;
    }
    if (b - min_val > 0) {
        ans += 1;
        b -= min_val;
    }

    // if there are still remaining strings of 'a' or 'b', we can add more good strings
    if (a > 0) {
        ans += min(a, b) * 2;
    }

    cout << ans << endl;

    return 0;
}