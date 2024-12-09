#include <iostream>
#include <string>

using namespace std;

int main() {
    string t;
    cin >> t;
    
    string s = "";
    for (int i = 0; i < t.length(); i++) {
        if (i % 2 == 0) {
            s = t[i] + s;
        } else {
            s = s + t[i];
        }
    }
    
    cout << s << endl;

    return 0;
}