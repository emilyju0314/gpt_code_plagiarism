#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int ans = 0;
        
        // insert your code here to calculate the minimum steps required

        cout << ans << endl;
    }
   
    return 0;
}
