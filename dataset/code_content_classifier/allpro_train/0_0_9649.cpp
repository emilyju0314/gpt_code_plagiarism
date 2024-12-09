#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    sort(s.begin(), s.end());

    vector<int> a(n), b(n);
    for(int i = 0; i < n-1; i++) {
        a[i] = s[i]/2;
        b[i] = s[i] - a[i];
    }

    a[n-1] = s[n-1];
    b[n-1] = 0;

    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}