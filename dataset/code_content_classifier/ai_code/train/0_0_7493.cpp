#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 10007;

int main() {
    int n;
    cin >> n;

    vector<int> tasks(n);

    for (int i = 0; i < n; i++) {
        cin >> tasks[i];
    }

    sort(tasks.begin(), tasks.end());

    long long totalTime = 0;
    for (int i = 0; i < n; i++) {
        totalTime = (totalTime + 1LL * tasks[i] * tasks[n - i - 1]) % MOD;
    }

    cout << totalTime << endl;

    return 0;
}