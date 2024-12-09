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
        vector<int> p(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i];
        }

        vector<int> result(n);
        result[0] = p[1];
        result[n-1] = p[0];

        for(int i = 1; i < n-1; i++) {
            result[i] = p[i];
        }

        for(int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}