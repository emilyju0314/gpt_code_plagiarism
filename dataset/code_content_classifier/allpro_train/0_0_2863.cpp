#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> piles(n);
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    sort(piles.begin(), piles.end());

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += piles[i];
    }

    if (piles[n-1] >= sum - piles[n-1] || sum % 2 == 1) {
        cout << "sjfnb" << endl;
    } else {
        cout << "cslnb" << endl;
    }

    return 0;
}