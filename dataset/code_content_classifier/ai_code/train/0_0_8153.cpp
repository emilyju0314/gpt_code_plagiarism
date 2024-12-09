#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        long long a, b, c;
        cin >> a >> b >> c;

        long long arr[3] = {a, b, c};
        sort(arr, arr+3);

        if (arr[0] == arr[1] && arr[1] == arr[2]) {
            cout << "0" << endl;
        } else if (arr[0] == arr[1] && arr[1] != arr[2]) {
            cout << abs(arr[0] - arr[1]) + abs(arr[1] - arr[2]) + 1 << endl;
        } else if (arr[0] != arr[1] && arr[1] == arr[2]) {
            cout << abs(arr[0] - arr[1]) + abs(arr[1] - arr[2]) + 1 << endl;
        } else {
            cout << max(abs(arr[0] - arr[1]), abs(arr[1] - arr[2])) * 2 << endl;
        }
    }

    return 0;
}