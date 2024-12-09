#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int f, w, h;
    cin >> f >> w >> h;

    long long totalArrangements = (f + 1LL) * (w + 1LL) - 1LL;
    long long dislikedArrangements = min((long long)w, h);

    long long favorableArrangements = totalArrangements - dislikedArrangements;
    long long ans = (favorableArrangements * power(totalArrangements, MOD - 2, MOD)) % MOD;

    cout << ans << endl;

    return 0;
}