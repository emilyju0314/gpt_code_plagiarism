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

        int average = sum / n;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != average) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}