#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int a, b, k;
        cin >> a >> b >> k;

        vector<int> boys(k);
        vector<int> girls(k);

        for(int i = 0; i < k; i++) {
            cin >> boys[i];
        }

        for(int i = 0; i < k; i++) {
            cin >> girls[i];
        }

        unordered_map<int, int> boyCount, girlCount;
        long long ans = 0;

        for(int i = 0; i < k; i++) {
            boyCount[boys[i]]++;
            girlCount[girls[i]]++;
        }

        for(int i = 0; i < k; i++) {
            ans += (k - boyCount[boys[i]] - girlCount[girls[i]] + 1);
        }

        cout << ans / 2 << endl;
    }

    return 0;
}