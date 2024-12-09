#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int count = n/2;
        for (int i = n-1; i >= 1 && count > 0; i--) {
            for (int j = i-1; j >= 0 && count > 0; j--) {
                if (a[i] % a[j] != 0 && find(a.begin(), a.end(), a[i] % a[j]) == a.end()) {
                    cout << a[i] << " " << a[j] << endl;
                    count--;
                }
            }
        }
    }

    return 0;
}