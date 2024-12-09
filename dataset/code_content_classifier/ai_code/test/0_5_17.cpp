#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        deque<int> dq;
        for(int i = 0; i < n; i++) {
            if(i%2 == 0) {
                dq.push_back(arr[i]);
            } else {
                dq.push_front(arr[i]);
            }
        }

        vector<int> sortedDQ(dq.begin(), dq.end());
        sort(sortedDQ.begin(), sortedDQ.end());

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(dq[i] != sortedDQ[i]) {
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}