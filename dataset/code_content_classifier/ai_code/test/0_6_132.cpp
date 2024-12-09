#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> restoreArray(vector<int>& b) {
    vector<int> a(3);
    a[0] = b[0];
    a[1] = b[1];
    a[2] = b[3];
    return a;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<int> b(7);
        for (int i = 0; i < 7; i++) {
            cin >> b[i];
        }

        vector<int> a = restoreArray(b);

        cout << a[0] << " " << a[1] << " " << a[2] << endl;
    }

    return 0;
}