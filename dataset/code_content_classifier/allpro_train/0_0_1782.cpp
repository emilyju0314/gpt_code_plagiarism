#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m;
    string s;
    cin >> m >> s;

    vector<int> selectedIndices;
    for (int i = 0; i < s.length(); i++) {
        if (i % m == 0) {
            selectedIndices.push_back(i);
        }
    }

    sort(selectedIndices.begin(), selectedIndices.end());

    string ans = "";
    for (int i : selectedIndices) {
        ans += s[i];
    }

    sort(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;
}