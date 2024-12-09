#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> c(m);
    for(int i = 0; i < m; i++) {
        cin >> c[i];
    }

    vector<int> a(n, 0);
    int pos = 0;
    for(int i = 0; i < m; i++) {
        if(pos + c[i] - 1 > n) {
            cout << "NO" << endl;
            return 0;
        }
        for(int j = pos; j < pos + c[i]; j++) {
            a[j] = i + 1;
        }
        pos += c[i] - 1;
    }

    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}