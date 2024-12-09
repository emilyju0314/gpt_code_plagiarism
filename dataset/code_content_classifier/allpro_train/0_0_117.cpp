#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> weights(n);
    int totalWeight = 0;
    int num100 = 0, num200 = 0;

    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        if (weights[i] == 100) {
            num100++;
        } else {
            num200++;
        }
        totalWeight += weights[i];
    }

    if (totalWeight % 200 != 0) {
        cout << "NO" << endl;
    } else {
        if (num100 % 2 != 0 && num100 > 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}