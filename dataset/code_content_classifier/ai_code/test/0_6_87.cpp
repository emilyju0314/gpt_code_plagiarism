#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, num;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> num;
            a[i] = num;
        }

        int operations = 0;
        int prev = 0;
        
        for(int i = 0; i < n; i++) {
            if(a[i] > i+1) {
                operations = max(operations, a[i] - (i+1));
            }
        }

        cout << operations << endl;
    }

    return 0;
}