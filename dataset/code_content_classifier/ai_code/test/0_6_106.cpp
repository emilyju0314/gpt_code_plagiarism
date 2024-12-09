#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        vector<long long> arr(n);

        arr[0] = 1;
        long long num = 1;
        for (int j = 1; j < n; ++j) {
            num *= 10;
            arr[j] = num;
        }

        for (int j = 0; j < n; ++j) {
            cout << arr[j] << " ";
        }
        cout << endl;
    }

    return 0;
}