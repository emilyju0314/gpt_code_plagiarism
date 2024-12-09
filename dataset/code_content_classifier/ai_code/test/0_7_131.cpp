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

    int minXor = INT_MAX;
    int x, y;

    for (int i = 0; i < n-1; i++) {
        int diff = chocolates[i+1] - chocolates[i];
        if (diff < minXor) {
            minXor = diff;
            x = i;
            y = i+1;
        }
    }

    int k = 0;
    while ((1 << k) < chocolates[y] - chocolates[x]) {
        k++;
    }

    cout << x+1 << " " << y+1 << " " << k << endl;

    return 0;
}