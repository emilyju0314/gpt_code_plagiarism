#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int seed, vmax;
vector<int> a;

int rnd() {
    int ret = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return ret;
}

int main() {
    int n, m;
    cin >> n >> m >> seed >> vmax;

    // Generate initial values
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i] = (rnd() % vmax) + 1;
    }

    // Perform operations
    for (int i = 0; i < m; i++) {
        int op = (rnd() % 4) + 1;
        int l = (rnd() % n) + 1;
        int r = (rnd() % n) + 1;

        if (l > r) {
            swap(l, r);
        }

        int x;
        if (op == 3) {
            x = (rnd() % (r - l + 1)) + 1;
        } else {
            x = (rnd() % vmax) + 1;
        }

        int y;
        if (op == 4) {
            y = (rnd() % vmax) + 1;
        }

        if (op == 1) {
            for (int j = l-1; j < r; j++) {
                a[j] += x;
            }
        } else if (op == 2) {
            for (int j = l-1; j < r; j++) {
                a[j] = x;
            }
        } else if (op == 3) {
            vector<int> temp(a.begin() + l-1, a.begin() + r);
            sort(temp.begin(), temp.end());
            cout << temp[x-1] << endl;
        } else if (op == 4) {
            long long sum = 0;
            for (int j = l-1; j < r; j++) {
                sum += (long long)pow(a[j], x) % y;
            }
            cout << sum % y << endl;
        }
    }

    return 0;
}