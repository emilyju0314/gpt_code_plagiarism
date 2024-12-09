#include "bits/stdc++.h"
using namespace std;
using i64 = long long;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    i64 N, K;
    cin >> N >> K;

    i64 ok = 0;
    i64 ng = K + 1;

    const auto isOK = [&](i64 x) {
        i64 sum = 0;
        i64 tmp = x;
        for (int i = 0; i < N; ++i) {
            sum += tmp;
            tmp /= 2;
            if (tmp <= 0) break;
        }
        return (sum <= K);
    };

    while (ng - ok > 1) {
        i64 mid = (ok + ng)/  2;
        if (isOK(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    cout << ok << endl;

    return 0;
}

