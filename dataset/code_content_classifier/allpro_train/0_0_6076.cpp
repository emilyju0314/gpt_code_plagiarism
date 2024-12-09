#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0, sum = 0;
    unordered_map<long long, int> prefixSums;
    prefixSums[0] = 1;

    for(int i = 0; i < n; i++) {
        sum += a[i];
        for(int j = 0; j*j <= sum; j++) {
            if(prefixSums.find(sum - j*j) != prefixSums.end()) {
                ans += prefixSums[sum - j*j];
            }
        }
        prefixSums[sum]++;
    }

    cout << ans << endl;

    return 0;
}