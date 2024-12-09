#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, d;
        cin >> n >> d;

        if(d < n || d > n*(n-1)/2) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;

            vector<int> parents(n);

            for(int i = 2; i <= n && d > 0; i++) {
                int j = min(d, i-1);
                parents[i-1] = i-j;
                d -= j;
            }

            for(int i = 2; i < n; i++) {
                cout << parents[i] << " ";
            }
            cout << parents[n] << endl;
        }
    }

    return 0;
}