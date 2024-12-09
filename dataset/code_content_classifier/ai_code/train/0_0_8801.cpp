#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long seed, vmax;
vector<int> a;

long long rnd() {
    long long ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;
}

void performOperation(int op, int l, int r, int x, int y) {
    if (l > r) {
        swap(l, r);
    }

    if (op == 1) {
        for (int i = l; i <= r; i++) {
            a[i] += x;
        }
    } else if (op == 2) {
        for (int i = l; i <= r; i++) {
            a[i] = x;
        }
    } else if (op == 3) {
        vector<int> sorted(a.begin() + l, a.begin() + r + 1);
        sort(sorted.begin(), sorted.end());
        cout << sorted[x - 1] << endl;
    } else if (op == 4) {
        long long sum = 0;
        for (int i = l; i <= r; i++) {
            sum += pow(a[i], x);
            sum %= y;
        }
        cout << sum << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m >> seed >> vmax;

    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = (rnd() % vmax) + 1;
    }

    for (int i = 0; i < m; i++) {
        int op = (rnd() % 4) + 1;
        int l = (rnd() % n) + 1;
        int r = (rnd() % n) + 1;
        int x = 0, y = 0;
        if (op == 3) {
            x = (rnd() % (r - l + 1)) + 1;
        } else {
            x = (rnd() % vmax) + 1;
        }
        if (op == 4) {
            y = (rnd() % vmax) + 1;
        }

        performOperation(op, l, r, x, y);
    }

    return 0;
}