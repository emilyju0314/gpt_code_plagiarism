#include <iostream>
#include <string>

using namespace std;

int main() {
    int k;
    cin >> k;
    
    string q;
    cin >> q;
    
    int n = q.length();
    
    if (k > n) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        int i = 0;
        while (i < k-1) {
            cout << q[i] << endl;
            i++;
        }
        cout << q.substr(i) << endl;
    }
    
    return 0;
}