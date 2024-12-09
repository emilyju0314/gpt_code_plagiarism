#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        permutation[i] = i + 1;
    }

    vector<int> ans;
    int cnt = factorial(n) / n;
    int idx = n - 1;

    while (ans.size() < n) {
        int choose = m / cnt;
        m %= cnt;

        ans.push_back(permutation[choose]);
        permutation.erase(permutation.begin() + choose);

        if (idx > 0) {
            cnt /= idx;
            idx--;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}