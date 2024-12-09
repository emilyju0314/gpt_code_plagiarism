#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canTransform(vector<int>& a, string& colors) {
    int n = a.size();
    vector<int> cnt(n+1, 0);
    for(int i = 0; i < n; i++) {
        if(colors[i] == 'R') {
            cnt[a[i]]++;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        string colors;
        cin >> colors;

        if(canTransform(a, colors)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}