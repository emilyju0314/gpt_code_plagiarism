#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> p(n);

    int odd_ans = -1;

    for (int i = 1; i <= n; i++) {
        cout << i << endl;
        cout.flush();
        cin >> p[i - 1];
        if (i % 2 == 1) {
            if (p[i - 1] == 0)
                odd_ans = m - 1;
        }
    }

    int l = 1, r = m;
    int cnt = 0;

    while (l < r) {
        int mid = (l + r) / 2;

        cout << mid << endl;
        cout.flush();
        int ans;
        cin >> ans;

        if (ans == 0)
            exit(0);

        if (((mid <= odd_ans) && (n % 2 == 1)) ^ (abs(mid - l) % 2 == 1) ^ (p[cnt++ % n] == 0))
            l = mid + 1;
        else
            r = mid;
    }

    return 0;
}