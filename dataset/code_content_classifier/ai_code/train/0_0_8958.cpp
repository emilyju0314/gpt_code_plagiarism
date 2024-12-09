#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> get_sum_of_permutations(const vector<int>& p, const vector<int>& q) {
    int n = p.size();
    vector<int> sum(n);

    vector<int> inv_p(n), inv_q(n);
    for (int i = 0; i < n; ++i) {
        inv_p[p[i]] = i;
        inv_q[q[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        sum[i] = inv_p[inv_q[i]];
    }

    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<int> p(n), q(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> q[i];
    }

    vector<int> sum = get_sum_of_permutations(p, q);

    for (int i = 0; i < n; ++i) {
        cout << sum[i] << " ";
    }

    return 0;
}