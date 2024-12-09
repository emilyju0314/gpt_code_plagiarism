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
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        int x = sum/n;
        
        for (int i = 0; i < n-1; i++) {
            cout << x << " ";
            sum -= a[i];
            x = sum/(n-i-1);
        }
        cout << sum << endl;
    }

    return 0;
}