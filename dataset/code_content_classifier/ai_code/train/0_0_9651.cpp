#include <iostream>
#include <vector>
using namespace std;

bool algorithmWorks(string subString) {
    return subString != "zyx" && subString != "xzy" && subString != "yxz";
}

int main() {
    string s;
    cin >> s;
    
    int n = s.length();
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int li, ri;
        cin >> li >> ri;
        
        string subString = s.substr(li-1, 3);
        
        if (ri - li >= 2 && algorithmWorks(subString)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}