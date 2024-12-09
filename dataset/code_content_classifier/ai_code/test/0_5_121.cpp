#include <iostream>
#include <string>
#include <vector>

using namespace std;

int min_operations(string a, string b) {
    int n = a.length();
    vector<int> diff(n);
    
    for (int i = 0; i < n; i++) {
        diff[i] = (a[i] != b[i]) ? 1 : 0;
    }
    
    for (int i = 1; i < n; i++) {
        diff[i] += diff[i - 1];
    }
    
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if ((diff[i] + cnt) % 2 != 0) {
            if (a[i] == b[i]) {
                return -1;
            }
            cnt++;
        }
    }
    
    return cnt;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        string a, b;
        cin >> a >> b;
        
        int minOps = min_operations(a, b);
        cout << minOps << endl;
    }
    
    return 0;
}