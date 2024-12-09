#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    const int MAX_X = 8192;
    vector<int> cnt(MAX_X, 0);

    for(int i=0; i<n; i++) {
        vector<int> new_cnt = cnt;
        for(int x=0; x<MAX_X; x++) {
            if(cnt[x] > 0) {
                new_cnt[x ^ a[i]] = 1;
            }
        }
        new_cnt[a[i]] = 1;
        cnt = new_cnt;
    }

    set<int> result;
    for(int x=0; x<MAX_X; x++) {
        if(cnt[x] > 0) {
            result.insert(x);
        }
    }

    cout << result.size() << endl;
    for(auto x : result) {
        cout << x << " ";
    }

    return 0;
}