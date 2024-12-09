#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<long long> cupcakes(n);
        for(int i = 0; i < n; i++) {
            cin >> cupcakes[i];
        }

        long long total = cupcakes[0];
        long long max_ending_here = cupcakes[0];
        long long max_so_far = cupcakes[0];

        for(int i = 1; i < n; i++) {
            max_ending_here = max(cupcakes[i], max_ending_here + cupcakes[i]);
            max_so_far = max(max_so_far, max_ending_here);
            total += cupcakes[i];
        }

        if(total > max_so_far) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}