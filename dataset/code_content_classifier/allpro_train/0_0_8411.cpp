#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int mex(set<int>& s) {
    int mex = 0;
    while (s.count(mex)) {
        mex++;
    }
    return mex;
}

int main() {
    int n;
    cin >> n;

    vector<int> ans;
    set<int> s;
    int lans = 0;

    for (int i = 0; i < n; i++) {
        int a, l, r, k;
        int a_, l_, r_, k_;
        cin >> a_ >> l_ >> r_ >> k_;

        a = (a_ + lans) % (n + 1);
        l = (l_ + lans) % (i + 1) + 1;
        r = (r_ + lans) % (i + 1) + 1;
        if (l > r) swap(l, r); 
        k = (k_ + lans) % (n + 1);

        for (int j = 0; j < r; j++) {
            s.insert((a + j) % (n + 1));
        }
        
        set<int> temp;
        for (auto it = s.lower_bound(a); it != s.end() && l <= r; it++, l++) {
            temp.insert(*it);
        }
        
        ans.push_back(mex(temp));
        lans = ans.back();
        s.clear();
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}