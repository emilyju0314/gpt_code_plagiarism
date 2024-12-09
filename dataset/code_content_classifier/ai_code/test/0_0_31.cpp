#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        long long sum = 0;
        
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        if(sum == 0) {
            for(int i = 0; i < n; i++) {
                cout << "1 ";
            }
            cout << endl;
        } else {
            int sgn = (sum > 0) ? 1 : -1;
            sum = abs(sum);

            for(int i = 0; i < n-1; i++) {
                int bi = sgn * (abs(a[i]) + sum - abs(a[i+1]));
                cout << bi << " ";
                sum -= abs(a[i]);
            }

            cout << sgn * abs(a[n-1]) << endl;
        }
    }

    return 0;
}