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

        vector<int> subset;
        for(int i = 0; i < n; i++) {
            subset.push_back(i+1);
        }
        
        cout << n << endl;
        for(int i = 0; i < n; i++) {
            cout << subset[i] << " ";
        }
        cout << endl;
    }

    return 0;
}