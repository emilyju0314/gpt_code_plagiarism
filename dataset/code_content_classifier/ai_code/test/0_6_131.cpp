#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> chocolates(n);
    for (int i = 0; i < n; i++) {
        cin >> chocolates[i];
    }

    sort(chocolates.begin(), chocolates.end());

    int x, y, m = 0;
    // Choose the last and the second to last element for x and y
    x = n - 1;
    y = n - 2;

    while (chocolates[x] != chocolates[y]) {
        chocolates[x] = chocolates[x] - chocolates[y];
        m++;
        sort(chocolates.begin(), chocolates.end());
    }

    cout << x + 1 << " " << y + 1 << " " << m << endl;

    return 0;
}