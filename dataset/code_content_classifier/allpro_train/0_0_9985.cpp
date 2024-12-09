#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> colors(n);
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    map<int, int> last_occurrence;
    int ans = n;
    int l = 0;
    for (int r = 0; r < n; r++) {
        last_occurrence[colors[r]] = r;
        while (last_occurrence.size() == last_occurrence.rbegin()->first) {
            ans = min(ans, r - l + 1);
            l = last_occurrence.begin()->second + 1;
            last_occurrence.erase(last_occurrence.begin());
        }
    }

    cout << ans << endl;

    return 0;
}