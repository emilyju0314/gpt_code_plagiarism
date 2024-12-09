#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    int m;
    cin >> s >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    reverse(s.begin(), s.end());

    for (int i = 0; i < m; i++) {
        reverse(s.begin() + a[i] - 1, s.begin() + s.length() - a[i] + 1);
    }

    cout << s << endl;

    return 0;
}