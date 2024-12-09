#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, t, c;
    cin >> n >> t >> c;

    vector<int> crimes(n);
    for (int i = 0; i < n; i++) {
        cin >> crimes[i];
    }

    int count = 0;
    int tempCount = 0;
    for (int i = 0; i < n; i++) {
        if (crimes[i] <= t) {
            tempCount++;
            if (tempCount == c) {
                count++;
            }
        } else {
            tempCount = 0;
        }
    }

    cout << count << endl;

    return 0;
}