#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    
    vector<pair<int, char>> parties;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        parties.push_back({x, 'a' + i});
    }

    sort(parties.rbegin(), parties.rend());

    vector<string> island(max(b, d), string(a + c, '.'));

    int p = 0;
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < a; j++) {
            if (parties[p].first > 0) {
                island[i][j] = parties[p].second;
                parties[p].first--;
            } else {
                p++;
                island[i][j] = parties[p].second;
                parties[p].first--;
            }
        }
    }

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < c; j++) {
            if (parties[p].first > 0) {
                island[i][j + a] = parties[p].second;
                parties[p].first--;
            } else {
                p++;
                island[i][j + a] = parties[p].second;
                parties[p].first--;
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < max(b, d); i++) {
        cout << island[i] << endl;
    }

    return 0;
}