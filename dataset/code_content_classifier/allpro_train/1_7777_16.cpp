#include <iostream>
using namespace std;

int main() {
    int m, n; cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            string s; cin >> s;
            if (s == "snuke") cout << (char) ('A' + j) << i + 1 << endl;
        }
    }
    cout << endl;
}
