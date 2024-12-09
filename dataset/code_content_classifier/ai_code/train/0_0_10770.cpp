#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minNum = arr[0];
    for (int i = 1; i < n; i++) {
        minNum = min(minNum, arr[i]);
    }

    bool divisible = true;
    for (int i = 0; i < n; i++) {
        if (arr[i] % minNum != 0) {
            divisible = false;
            break;
        }
    }

    if (divisible) {
        cout << minNum << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}