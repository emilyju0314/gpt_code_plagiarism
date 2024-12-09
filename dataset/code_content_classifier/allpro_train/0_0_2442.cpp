#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

bitset<2001> reachable[16][2001];
vector<pair<int, int>> operation[16][2001];
int n, k;
vector<int> num;

int main() {
    cin >> n >> k;
    num.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    reachable[0][1].set(0);
    for (int i = 0; i < n; ++i) {
        for (int sum = 1; sum <= 2000; ++sum) {
            for (int prev = 0; prev < 2000; ++prev) {
                if (!reachable[i][prev].test(sum - 1)) continue;

                int next_sum = (sum % k + num[i] % k) % k;
                reachable[i + 1][next_sum].set(sum - 1);
                operation[i + 1][next_sum].emplace_back(sum - 1, num[i]);
                
                next_sum = (sum % k + (num[i] / k) % k) % k;
                reachable[i + 1][next_sum].set(sum - 1);
                operation[i + 1][next_sum].emplace_back(sum - 1, num[i] / k);
            }
        }
    }

    if (!reachable[n][0].any()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int sum = 0;
        for (int i = n; i > 0; --i) {
            for (int prev = 0; prev < 2000; ++prev) {
                if (reachable[i][0].test(sum)) {
                    auto op = operation[i][0][0];
                    cout << op.first << " " << op.second << endl;
                    sum = op.first;
                    break;
                }
            }
        }
    }

    return 0;
}