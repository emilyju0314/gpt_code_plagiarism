#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> triplet(n + 1), straight(n + 1);
    vector<int> ans(n + 1), temp(n + 1);

    int t, s;
    cin >> t >> s;
    triplet[n] = t;
    straight[n] = s;

    cout << "+ 1" << endl;
    cout.flush();
    cin >> t >> s;
    triplet[1] = t - triplet[n];
    straight[1] = s - straight[n];

    cout << "+ 2" << endl;
    cout.flush();
    cin >> t >> s;
    triplet[2] = t - triplet[1];
    straight[2] = s - straight[1];

    cout << "+ 1" << endl;
    cout.flush();
    cin >> t >> s;
    triplet[1] = t - triplet[2];
    straight[1] = s - straight[2];

    cout << "+ 3" << endl;
    cout.flush();
    cin >> t >> s;
    triplet[3] = t - triplet[n];
    straight[3] = s - straight[n];

    ans[1] = (triplet[1] > 0) + (straight[1] > 0);
    ans[2] = (triplet[2] > 0) + (straight[2] > 0);
    ans[3] = (triplet[3] > 0) + (straight[3] > 0);
    ans[4] = triplet[n] > 0;

    cout << "+ 4" << endl;
    cout.flush();
    cin >> t >> s;
    triplet[4] = t - triplet[1] - triplet[2] - triplet[3];
    straight[4] = s - straight[1] - straight[2] - straight[3];

    ans[4] = (triplet[4] > 0) + (straight[4] > 0);

    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    
    return 0;
}