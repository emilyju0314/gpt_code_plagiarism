#include <iostream>
#include <string>
#include <vector>

using namespace std;

int min_operations(string a, string b) {
    int n = a.length();
    vector<int> operations(n, 0);
    int count = 0;

    for(int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (i > 0 && a[i-1] == '1')
                operations[i] = 1;
            else
                return -1;
            
            count++;
            a[i] = (a[i] == '1') ? '0' : '1';
            
            if (i+1 < n) {
                a[i+1] = (a[i+1] == '1') ? '0' : '1';
            }
        }
    }

    return count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        int result = min_operations(a, b);
        cout << result << endl;
    }

    return 0;
}