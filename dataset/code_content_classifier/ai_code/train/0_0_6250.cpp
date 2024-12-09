#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<string> strings(n+1);
        strings[0] = string(200, 'a');
        
        for (int i = 0; i < n; i++) {
            strings[i+1] = strings[i].substr(0, a[i]) + (char)('a' + (i+1) % 26) + string(200 - a[i] - 1, 'a');
        }

        for (int i = 0; i <= n; i++) {
            cout << strings[i] << endl;
        }
    }

    return 0;
}