#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> jars(2*n);
        for (int i = 0; i < 2*n; i++) {
            cin >> jars[i];
        }

        int count_strawberry = 0;
        int count_blueberry = 0;
        int diff = 0;
        int ans = 0;

        for (int i = 0; i < 2*n; i++) {
            if (jars[i] == 1) {
                count_strawberry++;
            } else {
                count_blueberry++;
            }

            if (i % 2 == 1) {
                diff = count_strawberry - count_blueberry;
                if (diff > 0) {
                    ans += diff;
                    count_strawberry -= diff;
                } else {
                    ans -= diff;
                    count_blueberry += diff;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}