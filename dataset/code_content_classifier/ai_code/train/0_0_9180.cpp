#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        
        unordered_map<int, int> subs;
        for (int j = l - 1; j < r; j++) {
            subs[a[j]]++;
        }

        int ans = 0;
        for (auto element : subs) {
            if (element.second == 1) {
                ans = element.first;
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}