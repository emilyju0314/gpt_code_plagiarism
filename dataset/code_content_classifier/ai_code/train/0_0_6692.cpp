#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int ans = 0;

    for(int k = 1; k <= n/3; ++k) {
        if(n % k == 0) {
            for(int i = 0; i < k; ++i) {
                int sum = 0;
                for(int j = i; j < n; j += k) {
                    sum += t[j];
                }
                ans = max(ans, sum);
            }
        }
    }

    cout << ans << endl;

    return 0;
}