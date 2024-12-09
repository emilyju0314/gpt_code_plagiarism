#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k, b, n;
    cin >> k >> b >> n;

    vector<int> digits(n);
    for(int i = 0; i < n; i++) {
        cin >> digits[i];
    }

    long long ans = 0;
    if(b == 0) {
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(digits[i] == b) {
                count++;
            } else {
                ans += count * (count + 1) / 2;
                count = 0;
            }
        }
        ans += count * (count + 1) / 2;
    } else {
        vector<int> prefixSum(n + 1);
        for(int i = 0; i < n; i++) {
            prefixSum[i + 1] = (prefixSum[i] + digits[i]) % (k - 1);
        }

        vector<long long> count(k - 1);
        count[0] = 1;
        for(int i = 0; i < n; i++) {
            ans += count[(prefixSum[i + 1] - b + k - 1) % (k - 1)];
            count[prefixSum[i + 1]]++;
        }
    }

    cout << ans << endl;

    return 0;
}