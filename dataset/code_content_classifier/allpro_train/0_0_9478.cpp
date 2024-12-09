#include <iostream>
#include <string>

using namespace std;

bool algorithmWorks(string s) {
    for (int i = 0; i <= s.length()-3; i++) {
        string sub = s.substr(i, 3);
        if (sub != "zyx" && sub != "xzy" && sub != "yxz") {
            return true;
        }
    }
    return false;
}

int main() {
    string s;
    int n;
    
    cin >> s;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int li, ri;
        cin >> li >> ri;
        if (algorithmWorks(s.substr(li-1, ri-li+1))) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}