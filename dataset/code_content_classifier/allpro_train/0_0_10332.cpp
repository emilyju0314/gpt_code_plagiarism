#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<long long> d(n);
        for(int i = 0; i < n; i++) {
            cin >> d[i];
        }

        long long cost = 0;
        long long prev_d = 0;
        for(int i = 1; i < n; i++) {
            if(d[i] < prev_d) {
                cout << -1 << endl;
                continue;
            }

            cost += (d[i] - prev_d);
            prev_d = d[i];
        }

        cout << cost << endl;
    }

    return 0;
}