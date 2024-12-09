#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    map<int, int> sums;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int max_sum = 0;
    vector<int> order;

    for (int i = 0; i < n; i++) {
        int cur_pos = i;
        int cur_sum = a[i];

        while (b[cur_pos] != -1) {
            cur_sum += a[b[cur_pos]];
            cur_pos = b[cur_pos];
        }

        sums[i] = cur_sum;
        max_sum += cur_sum;
    }

    cout << max_sum << endl;

    for (auto it = sums.rbegin(); it != sums.rend(); ++it) {
        cout << it->first + 1 << " ";
    }

    return 0;
}