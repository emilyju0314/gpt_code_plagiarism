#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int count1 = 1, count2 = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i-1]) {
            count1++;
        } else {
            count2++;
        }
    }

    long long ans = 1;
    for(int i = 0; i < count2-1; i++) {
        ans = (ans * 2) % MOD;
    }

    cout << ans << endl;

    return 0;
}