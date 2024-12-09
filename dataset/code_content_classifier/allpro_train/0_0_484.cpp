#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string findSubstring(int n, long long int num) {
    string s = to_string(num);
    for (int i = 1; i < min(100, (int)s.length()); i++) {
        string sub = s.substr(s.length() - i, i);
        if (s.find(sub) != string::npos) {
            return sub;
        }
    }
    return "";
}

int main() {
    int n;
    cin >> n;
    
    vector<long long int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++) {
        string sub = findSubstring(n, 2 * a[i]);
        if (!sub.empty()) {
            cout << sub.length() << endl;
        } else {
            cout << 1 << endl;
        }
    }
    
    return 0;
}