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

        vector<long long> x(n), y(n), z(n);

        for(int i = 0; i < n; i++) {
            cin >> x[i] >> y[i] >> z[i];
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        sort(z.begin(), z.end());

        long long optimal_x = x[n/2];
        long long optimal_y = y[n/2];
        long long optimal_z = z[n/2];

        cout << optimal_x << " " << optimal_y << " " << optimal_z << endl;
    }

    return 0;
}