#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (k == 1) {
        cout << *min_element(a.begin(), a.end()) << endl;
    } else if (k >= 3) {
        cout << *max_element(a.begin(), a.end()) << endl;
    } else {
        cout << max(*a.begin(), *a.rbegin()) << endl;
    }

    return 0;
}