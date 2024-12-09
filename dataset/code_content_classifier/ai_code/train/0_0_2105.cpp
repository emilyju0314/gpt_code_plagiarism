#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> cnt(k, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') continue;
        
        cnt[s[i] - 'a']++;
    }

    for (int i = 0; i < k; i++) {
        ans = max(ans, cnt[i]);
    }

    cout << ans << endl;

    return 0;
}