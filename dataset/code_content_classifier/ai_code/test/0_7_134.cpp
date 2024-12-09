#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for(int i = 0; i < n - 1; i++) {
            if(a[i] % a[i+1] != 0 && a[i+1] % a[i] != 0) {
                cout << a[i] << endl;
                break;
            }
        }
        cout << "0" << endl;
    }

    return 0;
}