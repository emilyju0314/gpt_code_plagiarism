#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        f[i]--;
    }

    vector<long long> income(n);
    vector<long long> inc_self(n);

    for (int i = 0; i < n; i++) {
        income[f[i]] += t[i];
        inc_self[f[i]] = t[i];
    }

    long long overall_min = 0, overall_max = 0;
    for (int i = 0; i < n; i++) {
        overall_min += inc_self[i];
        overall_max += income[i];
    }

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int a, b;
            cin >> a >> b;
            a--; b--;

            income[f[a]] -= t[a];
            if (f[a] != a) {
                income[f[a]] -= t[f[a]];
            }

            f[a] = b;

            income[f[a]] += t[a];
            if (f[a] != a) {
                income[f[a]] += t[f[a]];
            }
        } else if (type == 2) {
            int a;
            cin >> a;
            a--;

            cout << income[a] << endl;
        } else {
            cout << overall_min << " " << overall_max << endl;
        }
    }

    return 0;
}