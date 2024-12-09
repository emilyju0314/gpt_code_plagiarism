#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<pair<int, int>> erased;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        erased.push_back({a, b});
    }

    vector<int> ans(w+1);
    for (int i = 1; i <= w; i++) {
        ans[i] = i;
    }

    for (int i = 0; i < n; i++) {
        int a = erased[i].first;
        int b = erased[i].second;
        swap(ans[b], ans[b+1]);
    }

    for (int i = 1; i <= w; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}