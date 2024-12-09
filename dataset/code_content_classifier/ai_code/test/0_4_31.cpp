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
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int sum = 0;
        vector<int> b(n);
        for(int i = 0; i < n-1; i++) {
            b[i] = 1;
            sum += a[i] * b[i];
        }

        b[n-1] = -sum;
        
        for(int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }

    return 0;
}