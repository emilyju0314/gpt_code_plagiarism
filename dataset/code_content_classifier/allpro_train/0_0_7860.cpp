#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int max_comb = 0;
    int a_i, a_j;

    for (int i = 1; i < n; i++) {
        int comb = min(a[i], a[n-1]-a[i]);
        if (comb > max_comb) {
            max_comb = comb;
            a_i = a[n-1];
            a_j = a[i];
        }
    }

    cout << a_i << " " << a_j << endl;

    return 0;
}