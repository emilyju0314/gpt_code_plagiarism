#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;

    long long ans = 0;

    // Calculate the cost of buying N liters of ice tea
    long long S2 = min({Q * 4, H * 2, S});  // Cost of 0.5 liter
    long long S1 = min(S2 * 2, D);  // Cost of 1 liter
    ans += (N / 2) * S1;  // Buy 1 liter bottles
    ans += (N % 2) * S2;  // Buy 0.5 liter bottles

    cout << ans << endl;

    return 0;
}