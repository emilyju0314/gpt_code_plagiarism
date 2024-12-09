#include <iostream>
#include <vector>
#include <string>

using namespace std;

int min_operations(string a, string b) {
    int n = a.size();
    vector<int> operations;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] != b[i]) {
            a[i] = '1' - a[i] + '0';
            a[i + 1] = '1' - a[i + 1] + '0';
            operations.push_back(i);
        }
    }
    
    if (a[n - 1] == b[n - 1]) {
        return operations.size();
    } else {
        return -1;
    }
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        
        int res = min_operations(a, b);
        cout << res << endl;
    }
    
    return 0;
}