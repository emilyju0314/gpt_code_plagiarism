#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 100005;

int digit_sum(int n) {
    int sum = n;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int T;
    cin >> T;

    int ans[MAXN];
    memset(ans, 0, sizeof(ans));

    for (int i = 1; i < MAXN; ++i) {
        int sum = digit_sum(i);
        if (sum < MAXN && ans[sum] == 0) {
            ans[sum] = i;
        }
    }

    while (T--) {
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }

    return 0;
}
