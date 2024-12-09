#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

long long countNearlyFullSubsequences(int n, vector<int>& a) {
    long long s = 0;
    for(int i = 0; i < n; i++) {
        s += a[i];
    }

    map<long long, int> cnt;
    for(int mask = 1; mask < (1 << n); mask++) {
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                sum += a[i];
            }
        }
        cnt[sum]++;
    }

    long long res = 0;
    for(int mask = 1; mask < (1 << n); mask++) {
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                sum += a[i];
            }
        }
        if(cnt.find(s - 1 - sum) != cnt.end()) {
            res += cnt[s - 1 - sum];
        }
    }

    return res;
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int j = 0; j < n; j++) {
            cin >> a[j];
        }

        cout << countNearlyFullSubsequences(n, a) << endl;
    }

    return 0;
}