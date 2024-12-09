#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    vector<char> s(n);
    set<char> distinctChars;

    char c = 'a';
    for (int i = 0; distinctChars.size() < k; i++) {
        s[p[i]-1] = c;
        distinctChars.insert(c);
        c++;
    }

    for (int i = 0; i < n-1; i++) {
        if (s[p[i]-1] > s[p[i+1]-1] || s[q[i]-1] > s[q[i+1]-1]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    for (char ch : s) {
        cout << ch;
    }
    cout << endl;

    return 0;
}