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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            int bigger = max(a[i], a[i + 1]);
            int smaller = min(a[i], a[i + 1]);
            while (bigger > 2 * smaller) {
                smaller *= 2;
                count++;
            }
        }
        
        cout << count << endl;
    }

    return 0;
}