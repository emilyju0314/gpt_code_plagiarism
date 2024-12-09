#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 30005;

int fib[MAXN];
int a[MAXN];
int dp[MAXN];

int main() {
    int n, m;
    cin >> n >> m;

    fib[1] = fib[2] = 1;
    for(int i = 3; i < MAXN; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % m;
    }

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    while(q--) {
        int l, r;
        cin >> l >> r;

        vector<int> unique_elements;
        for(int i = l; i <= r; i++) {
            bool found = false;
            for(int j = 0; j < unique_elements.size(); j++) {
                if(unique_elements[j] == a[i]) {
                    found = true;
                    break;
                }
            }
            if(!found) {
                unique_elements.push_back(a[i]);
            }
        }

        sort(unique_elements.begin(), unique_elements.end());

        int ans = 0;
        for(int i = 0; i < unique_elements.size(); i++) {
            dp[i+1] = (dp[i] + fib[i+1]) % m;
        }

        for(int i = 0; i < unique_elements.size(); i++) {
            ans = (ans + 1LL * unique_elements[i] * dp[i+1]) % m;
        }

        cout << ans << endl;
    }

    return 0;
}