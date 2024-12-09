#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<string, int>> attempts(m);
    for (int i = 0; i < m; i++) {
        cin >> attempts[i].first >> attempts[i].second;
    }

    int ans = 0;

    for (int code = 0; code < (1 << n); code++) {
        bool valid = true;

        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (((1 << j) & code) && attempts[i].first[j] == '1') {
                    count++;
                }
            }

            if (count != attempts[i].second) {
                valid = false;
                break;
            }
        }

        if (valid) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}