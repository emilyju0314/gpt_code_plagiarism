#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int count = 1;
        for (int i = 0; i < n - 1; i++) {
            if ((arr[i] + arr[i + 1]) % m != 0) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}