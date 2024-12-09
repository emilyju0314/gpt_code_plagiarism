#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int m;
    cin >> m;

    vector<int> a(m);
    int total_students = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        total_students += a[i];
    }

    long long ans = 0;
    long long sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < a[i]; j++) {
            sum = (sum + ((long long)a[i] * (total_students - a[i])) % MOD) % MOD;
        }
    }

    ans = ((total_students - 1) % MOD * sum) % MOD;
    cout << ans << endl;

    return 0;
}