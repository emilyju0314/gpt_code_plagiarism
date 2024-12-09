#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    
    for(int mask = 0; mask < (1 << n); mask++) {
        if(__builtin_popcount(mask) != m) continue;
        
        vector<int> subseq;
        for(int i = 0; i < n; i++) {
            if((mask & (1 << i)) != 0) {
                subseq.push_back(a[i]);
            }
        }

        long long sum = 0;
        for(int i = 0; i < subseq.size(); i++) {
            sum += m * subseq[i];
            for(int j = i+1; j < subseq.size(); j++) {
                int min_val = *min_element(subseq.begin() + i, subseq.begin() + j + 1);
                sum -= min_val;
            }
        }

        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}