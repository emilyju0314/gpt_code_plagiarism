#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n_r, n_g, n_b;
        cin >> n_r >> n_g >> n_b;

        vector<long long> red(n_r), green(n_g), blue(n_b);
        for (int i = 0; i < n_r; i++) {
            cin >> red[i];
        }
        for (int i = 0; i < n_g; i++) {
            cin >> green[i];
        }
        for (int i = 0; i < n_b; i++) {
            cin >> blue[i];
        }

        sort(red.begin(), red.end());
        sort(green.begin(), green.end());
        sort(blue.begin(), blue.end());

        long long ans = LLONG_MAX;
        for (int i = 0; i < n_r; i++) {
            auto it1 = lower_bound(green.begin(), green.end(), red[i]);
            if (it1 == green.end())
                it1--;

            for (int j = 0; j < n_b; j++) {
                auto it2 = lower_bound(blue.begin(), blue.end(), green[it1 - green.begin()]);
                if (it2 == blue.end())
                    it2--;

                long long sum = pow((red[i] - green[it1 - green.begin()]), 2)
                             + pow((green[it1 - green.begin()] - blue[it2 - blue.begin()]), 2)
                             + pow((blue[it2 - blue.begin()] - red[i]), 2);

                ans = min(ans, sum);

                if (it2 != blue.begin()) {
                    sum = pow((red[i] - green[it1 - green.begin()]), 2)
                        + pow((green[it1 - green.begin()] - blue[it2 - blue.begin() - 1]), 2)
                        + pow((blue[it2 - blue.begin() - 1] - red[i]), 2);

                    ans = min(ans, sum);
                }
                if (it1 != green.begin()) {
                    sum = pow((red[i] - green[it1 - green.begin() - 1]), 2)
                        + pow((green[it1 - green.begin() - 1] - blue[it2 - blue.begin()]), 2)
                        + pow((blue[it2 - blue.begin()] - red[i]), 2);

                    ans = min(ans, sum);

                    if (it2 != blue.begin()) {
                        sum = pow((red[i] - green[it1 - green.begin() - 1]), 2)
                            + pow((green[it1 - green.begin() - 1] - blue[it2 - blue.begin() - 1]), 2)
                            + pow((blue[it2 - blue.begin() - 1] - red[i]), 2);

                        ans = min(ans, sum);
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}