#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    multiset<pair<int, int>> s;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s.insert({-a[i], i});
    }

    vector<int> ans;
    while(!s.empty()) {
        auto it = *s.begin();
        s.erase(s.begin());
        if(it.first < k) {
            ans.push_back(it.second + 1);
        } else {
            break;
        }
    }

    cout << ans.size() << endl;
    for(int num : ans) {
        cout << num << endl;
    }

    return 0;
}