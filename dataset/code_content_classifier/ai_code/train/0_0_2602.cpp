#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

bool isPerfectSquare(long long num) {
    long long root = sqrt(num);
    return (root*root == num);
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while(q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        unordered_map<long long, int> freq;

        int ans = 0;
        for(int i = l; i < r; i++) {
            long long cur = a[i];
            for(int j = i+1; j <= r; j++) {
                cur *= a[j];
                while (cur % 2 == 0) {
                    cur /= 2;
                    freq[2]++;
                }
                for(long long k = 3; k*k <= cur; k += 2) {
                    while(cur % k == 0) {
                        cur /= k;
                        freq[k]++;
                    }
                }
                if(cur > 1) {
                    freq[cur]++;
                }

                int flag = 0;
                for(const auto& it: freq) {
                    flag += it.second % 2;
                    freq[it.first] = 0;
                }

                if(flag == 0) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}