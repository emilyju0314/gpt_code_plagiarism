#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> count(6, 0);

    for (int i = 0; i < n; i++) {
        if (a[i] == 4) {
            count[0]++;
        } else if (a[i] == 8 && count[0] > count[1]) {
            count[1]++;
        } else if (a[i] == 15 && count[1] > count[2]) {
            count[2]++;
        } else if (a[i] == 16 && count[2] > count[3]) {
            count[3]++;
        } else if (a[i] == 23 && count[3] > count[4]) {
            count[4]++;
        } else if (a[i] == 42 && count[4] > count[5]) {
            count[5]++;
        }
    }

    int removals = n - (6 * count[5]);
    cout << removals << endl;

    return 0;
}