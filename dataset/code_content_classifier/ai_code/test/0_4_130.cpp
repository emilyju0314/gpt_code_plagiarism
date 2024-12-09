#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> res(n+1, 0);
        int cnt = 0;

        for(int i = 1; i <= n; i += 3) {
            if(i+2 <= n) {
                cout << "? " << i << " " << i+1 << " " << i+2 << endl;
                int r;
                cin >> r;
                res[i] = res[i+1] = res[i+2] = r;
                cnt += r;
            }
        }

        if(cnt <= n/3) {
            for(int i = 1; i <= n; i++) {
                if(res[i] == 0) {
                    cout << "? 1 " << i << " " << ((i==n) ? 2 : i+1) << endl;
                    int r;
                    cin >> r;
                    res[i] = r;
                    cnt += r;
                }
            }
        } else {
            for(int i = 1; i <= n; i++) {
                if(res[i] == 1) {
                    cout << "? 1 " << i << " " << ((i==n) ? 2 : i+1) << endl;
                    int r;
                    cin >> r;
                    res[i] = r;
                    cnt += r;
                }
            }
        }

        cout << "! " << cnt;
        for(int i = 1; i <= n; i++) {
            if(res[i] == 1) {
                cout << " " << i;
            }
        }
        cout << endl;
        cout.flush();
    }

    return 0;
}