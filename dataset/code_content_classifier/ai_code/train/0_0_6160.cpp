#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    long long max_val = 0;
    int count = 1;
    long long prefix_sum = 0;
    multiset<int> max_heap;

    for (int i = 0; i < k; i++) {
        prefix_sum += p[i];
        max_heap.insert(p[i]);
    }

    max_val = prefix_sum;

    for (int i = k; i < n; i++) {
        prefix_sum = (prefix_sum + p[i] - *max_heap.begin()) % MOD;
        max_val = max(max_val, prefix_sum);

        if (p[i] > *max_heap.begin()) {
            max_heap.erase(max_heap.begin());
            max_heap.insert(p[i]);
        }
    }

    for (int i = 0; i < n - k; i++) {
        if (prefix_sum == max_val) {
            count = (count * 1LL * (i + 1)) % MOD;
        }
        
        prefix_sum = (prefix_sum + p[i] - p[i+k] + MOD) % MOD;

        max_heap.erase(max_heap.find(p[i]));
        max_heap.insert(p[i+k]);

        max_val = max(max_val, prefix_sum);
    }

    if (prefix_sum == max_val) {
        count = (count * 1LL * (n - k + 1)) % MOD;
    }

    cout << max_val << " " << count << endl;

    return 0;
}