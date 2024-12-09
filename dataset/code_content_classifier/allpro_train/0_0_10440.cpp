#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int count = 0;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;

        if (ai == 1) {
            count++;
        }
    }

    if (count == 1 || count == 0 || count == n-1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}