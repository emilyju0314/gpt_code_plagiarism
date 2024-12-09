#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    const int MAXN = 2e5 + 10;
    vector<int> cnt(MAXN, 0);
    for(int i = 0; i < n; i++) {
        cnt[arr[i]]++;
    }

    int max_freq = *max_element(cnt.begin(), cnt.end());
    vector<int> freq_count(max_freq + 1, 0);
    for(int i = 1; i < MAXN; i++) {
        freq_count[cnt[i]]++;
    }

    int ans = 0;
    for(int f = 1; f <= max_freq; f++) {
        int cur_count = freq_count[f];
        if(cur_count < 2) continue;
        int l = 1, r = f, curr = 0;
        while(r < MAXN) {
            curr += freq_count[r];
            curr -= freq_count[l-1];
            ans = max(ans, min(l-1, curr));
            l++; r++;
        }
    }

    cout << ans << endl;

    return 0;
}