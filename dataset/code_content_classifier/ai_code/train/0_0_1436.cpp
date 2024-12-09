#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<long long> t(n);
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> f[i];
        f[i]--; // 0-indexed
    }

    vector<int> followers(n);
    vector<long long> income(n);
    for (int i = 0; i < n; i++) {
        followers[f[i]]++;
        income[f[i]] += t[i];
    }

    long long maxIncome = *max_element(income.begin(), income.end());

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int fanpage, newFollow;
            cin >> fanpage >> newFollow;
            fanpage--; newFollow--;

            followers[f[fanpage]]--;
            income[f[fanpage]] -= t[fanpage];
            followers[newFollow]++;
            income[newFollow] += t[fanpage;

            f[fanpage] = newFollow;

            maxIncome = max(maxIncome, income[newFollow]);
        } else if (type == 2) {
            int company;
            cin >> company;
            company--;

            cout << income[company] << "\n";
        } else {
            long long minIncome = *min_element(income.begin(), income.end());
            cout << minIncome << " " << maxIncome << "\n";
        }
    }

    return 0;
}