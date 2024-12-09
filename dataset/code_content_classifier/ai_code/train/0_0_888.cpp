#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> carrots(n);
    for (int i = 0; i < n; i++) {
        cin >> carrots[i];
    }

    sort(carrots.begin(), carrots.end());

    int sum = 0;
    int currRabbits = k;
    int idx = n - 1;

    while (currRabbits > 0) {
        int cnt = min(currRabbits, carrots[idx]);
        sum += cnt * cnt;
        currRabbits -= cnt;
        idx--;
    }

    cout << sum << endl;

    return 0;
}