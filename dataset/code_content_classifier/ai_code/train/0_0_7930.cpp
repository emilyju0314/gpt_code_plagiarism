#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int c, n;
    cin >> c >> n;

    vector<int> coins;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        coins.push_back(x);
    }

    sort(coins.begin(), coins.end());

    int total = 0;
    int result = 0;

    for (int i = 0; i < n; i++) {
        if (total < c) {
            total += coins[i];
            result++;
        } else {
            break;
        }
    }

    if (total >= c) {
        cout << result << endl;
    } else {
        cout << "Greed is good" << endl;
    }

    return 0;
}