#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, p, k;
    cin >> n >> p >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> count;
    for(int i = 0; i < n; i++) {
        int curr = (a[i] * a[i] * a[i] + a[i]) % p;
        count[curr]++;
    }

    long long ans = 0;
    for(auto &x : count) {
        int rem = (k - x.first + p) % p;
        if(count.find(rem) != count.end()) {
            ans += 1LL * x.second * count[rem];
        }
    }

    cout << ans << endl;

    return 0;
}