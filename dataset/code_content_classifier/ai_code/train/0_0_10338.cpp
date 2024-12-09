#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long moves = 0;
    for(int i = 0; i < n; i++) {
        moves += abs(a[i] - (i + 1));
    }

    cout << moves << endl;

    return 0;
}