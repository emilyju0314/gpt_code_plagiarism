#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = 0;
    for(int i = 30; i >= 0; i--) {
        int res = ans | (1 << i);
        vector<int> temp;
        for(int j = 0; j < n; j++) {
            temp.push_back(a[j] & res);
        }
        sort(temp.begin(), temp.end());
        bool ok = true;
        for(int j = 0; j < n; j++) {
            if(temp[j] != a[j]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            ans = res;
        }
    }

    cout << ans << endl;

    return 0;
}