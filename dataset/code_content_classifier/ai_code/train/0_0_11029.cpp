#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;

        // Logic to calculate the answer to Yaroslav's query
        long long answer = 0;
        for (int j = l - 1; j <= r - 1; j++) {
            for (int k = j; k <= r - 1; k++) {
                if (p[k] % p[j] == 0) {
                    answer++;
                }
            }
        }

        cout << answer << endl;
    }

    return 0;
}