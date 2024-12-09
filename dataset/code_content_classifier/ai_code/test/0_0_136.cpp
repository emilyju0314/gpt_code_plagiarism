#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> b(n);
        long long sum = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            sum += b[i];
        }

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = b[(i+1)%n] - b[i%n];
        }

        long long total = 0;
        bool possible = true;
        for (int i = 0; i < n; i++) {
            total += a[i];
            if (total <= 0 || total % n != 0) {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}