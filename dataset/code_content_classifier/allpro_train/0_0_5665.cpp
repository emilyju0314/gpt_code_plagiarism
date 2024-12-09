#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define MOD 1000000007

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    unordered_map<int, int> prime_factors_count;
    for(int i=0; i<n; i++) {
        int num = a[i];
        for(int j=2; j*j <= num; j++) {
            while(num % j == 0) {
                prime_factors_count[j]++;
                num /= j;
            }
        }
        if(num > 1) {
            prime_factors_count[num]++;
        }
    }

    ll ans = 1;
    for(auto it : prime_factors_count) {
        ans = (ans * (it.second+1)) % MOD;
    }

    cout << ans << endl;

    return 0;
}