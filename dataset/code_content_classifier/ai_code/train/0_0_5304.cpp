#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n;
        
        vector<int> red(n);
        for(int i = 0; i < n; i++) {
            cin >> red[i];
        }

        cin >> m;

        vector<int> blue(m);
        for(int i = 0; i < m; i++) {
            cin >> blue[i];
        }

        long long max_sum = 0, sum = 0;
        int i = 0, j = 0;

        while(i < n && j < m) {
            if(red[i] < blue[j]) {
                sum += red[i++];
            } else {
                sum += blue[j++];
            }
            max_sum = max(max_sum, sum);
        }

        while(i < n) {
            sum += red[i++];
            max_sum = max(max_sum, sum);
        }

        while(j < m) {
            sum += blue[j++];
            max_sum = max(max_sum, sum);
        }

        cout << max_sum << endl;
    }

    return 0;
}