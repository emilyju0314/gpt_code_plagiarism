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

        vector<int> a(n);
        vector<int> freq(n + 1, 0);

        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] < n) {
                freq[a[i]]++;
            }
        }

        int mex = -1;
        for(int i = 0; i <= n; i++) {
            if(freq[i] == 0) {
                mex = i;
                break;
            }
        }

        int operations = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(a[i] > mex) {
                freq[a[i]]--;
                a[i] = mex;
                freq[a[i]]++;
                operations++;
            }

            if(a[i] == mex) {
                mex = -1;
                while(freq[++mex]) {}
            }
        }

        vector<int> result(n + 1, -1);
        for(int i = 0; i <= n; i++) {
            if(freq[i] == 0) {
                result[i] = operations;
            }
        }

        for(int i = 0; i <= n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}