#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int j = 0; j < n; j++) {
            cin >> a[j];
        }

        cout << n << endl;
        for(int j = 1; j <= n; j++) {
            cout << j << " " << j % n + 1 << " " << a[j-1] << " " << a[j % n] << endl;
        }
    }

    return 0;
}