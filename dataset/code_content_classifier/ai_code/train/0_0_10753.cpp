#include <iostream>
#include <vector>
#include <string>

using namespace std;

string getYearName(vector<string>& s, vector<string>& t, int n, int m, int y) {
    int idx_s = (y - 1) % n;
    int idx_t = (y - 1) % m;
    return s[idx_s] + t[idx_t];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<string> t(m);
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int y;
        cin >> y;
        string yearName = getYearName(s, t, n, m, y);
        cout << yearName << endl;
    }

    return 0;
}