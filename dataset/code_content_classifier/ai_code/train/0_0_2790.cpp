#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> b(n);
        for(int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<int> a(n);

        a[0] = b[0]; // First element
        a[n-1] = b[1]; // Second element

        for(int i = 1; i < n-1; i++) {
            if(i % 2 == 1) {
                a[i] = b[(i+2)/2];
            } else {
                a[i] = b[n - (i/2)];
            }
        }

        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}