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

        int i = 0, j = 1, k = 2;
        while(k < n) {
            if(a[i] + a[j] <= a[k]) {
                cout << i+1 << " " << j+1 << " " << k+1 << endl;
                break;
            }
            i++;
            j++;
            k++;
        }

        if(k == n) {
            cout << -1 << endl;
        }
    }

    return 0;
}