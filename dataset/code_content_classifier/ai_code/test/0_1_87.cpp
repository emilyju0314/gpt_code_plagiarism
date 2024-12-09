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

        int operations = 0;
        for(int i = 1; i < n; i++) {
            if(a[i] > i+1) {
                operations += (a[i] - (i + 1));
                a[i] = i + 1;
            }
        }

        cout << operations << endl;
    }

    return 0;
}