#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        vector<int> x(m);

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        for (int i = 0; i < m; i++) {
            cin >> x[i];
        }

        if (sum <= 0) {
            for (int i = 0; i < m; i++) {
                cout << "-1 ";
            }
            cout << endl;
        } else {
            for (int i = 0; i < m; i++) {
                long long remaining_sum = x[i] - sum;
                long long cycles = (remaining_sum + sum - 1) / sum;
                long long answer = cycles * n;
                for (int j = 0; j < n; j++) {
                    if (answer % n == j) {
                        long long current_sum = 0;
                        int k = j;
                        while (current_sum + a[k] < x[i]) {
                            current_sum += a[k];
                            k = (k + 1) % n;
                            answer++;
                        }
                    }
                }
                cout << answer << " ";
            }
            cout << endl;
        }
    }

    return 0;
}