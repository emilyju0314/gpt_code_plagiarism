#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        if (sum % 2 == 0) {
            cout << n << endl;
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << endl;
        } else {
            int index = -1;
            for (int i = 0; i < n; i++) {
                if (a[i] % 2 == 0) {
                    index = i;
                    break;
                }
            }

            if (index != -1) {
                cout << 1 << endl;
                cout << index + 1 << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}