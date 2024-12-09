#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    if (k > (1LL * n * (n - 1)) / 2) {
        cout << "Impossible" << endl;
        return 0;
    }

    vector<char> ans(2 * n, ')');

    long long curr_sum = 0;
    int i = 1;
    while (curr_sum < k) {
        ans[i] = '(';
        curr_sum += i;
        i += 2;
    }

    cout << string(ans.begin(), ans.end()) << endl;

    return 0;
}