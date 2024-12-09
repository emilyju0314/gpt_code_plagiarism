#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string n;
    cin >> n;
    
    int len = n.length();
    
    bool found = false;
    
    for(int i = len - 1; i >= 0; i--) {
        if((n[i] - '0') % 2 == 0) {
            for(int j = i - 1; j >= 0; j--) {
                if((n[j] - '0') % 2 == 0) {
                    swap(n[i], n[j]);
                    found = true;
                    break;
                }
            }
        }
        if(found) {
            break;
        }
    }
    
    if(found) {
        cout << n << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}