#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    int leftCount = 0, hashCount = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            leftCount++;
        } else if (s[i] == '#') {
            hashCount++;
        }
    }

    if (s[n - 1] == '(' || leftCount <= hashCount) {
        cout << "-1" << endl;
        return 0;
    }

    int extra = leftCount - hashCount;
    int hashIndex = -1;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') {
            hashIndex = i;
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '#') {
            if (extra >= 2 && i != hashIndex) {
                cout << "2" << endl;
                extra -= 2;
            } else if (extra == 1) {
                cout << "1" << endl;
                extra--;
            } else {
                cout << "0" << endl;
            }
        }
    }

    return 0;
}