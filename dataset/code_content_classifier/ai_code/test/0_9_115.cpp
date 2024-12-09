#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, h;
        cin >> n >> h;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int start = 1, end = 1e9;
        int result = 1e9;

        while(start <= end) {
            int mid = (start + end) / 2;
            vector<int> temp = a;
            int damage = 0;

            for(int i = 0; i < n; i++) {
                damage += temp[i] / mid;
                if(temp[i] % mid != 0) {
                    damage++;
                }
            }

            if(damage <= h) {
                result = min(result, mid);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        cout << result << endl;
    }

    return 0;
}