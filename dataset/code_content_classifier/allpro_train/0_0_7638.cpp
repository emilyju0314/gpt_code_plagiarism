#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    long long ans = a[0];
    for (int i = 1; i < n; i++) {
        vector<long long> temp;
        temp.push_back(a[i]);

        for (int j = 0; j < temp.size(); j++) {
            bool add = true;
            for (int k = i + 1; k < n; k++) {
                if ((temp[j] & a[k]) == temp[j]) {
                    temp.push_back(temp[j] | a[k]);
                    add = false;
                    break;
                }
            }
            if (add) {
                ans += temp[j];
            }
        }
    }

    cout << ans << endl;

    return 0;
}