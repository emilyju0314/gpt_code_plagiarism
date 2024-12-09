#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> b(n);
        long long total_sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> b[i];
            total_sum += b[i];
        }

        if(total_sum % n != 0) {
            cout << "NO" << endl;
            continue;
        }

        long long sum = total_sum / n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            a[i] = (2 * (b[i] - sum) + sum) / n;
        }

        long long rem = 0;
        for(int i = 0; i < n; i++) {
            rem += a[(i + 1) % n] - a[i];
        }

        if(rem == sum) {
            cout << "YES" << endl;
            for(int i = 0; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}