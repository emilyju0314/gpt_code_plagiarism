#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << "? 1 1 " << n-1 << " 1" << endl;
    string ans;
    cin >> ans;
    
    if(ans == "NO") {
        cout << "? 1 1 1 " << n-1 << endl;
        cin >> ans;
    }

    string s = "";
    int i = 1, j = 1;

    for(int k = 0; k < 2*n - 3; ++k) {
        if(i == n-1) {
            s += "R";
            j++;
        } else if(j == n-1) {
            s += "D";
            i++;
        } else {
            cout << "? " << i << " " << j+1 << " " << n << " " << n-1 << endl;
            cin >> ans;
            if(ans == "YES") {
                s += "R";
                j++;
            } else {
                s += "D";
                i++;
            }
        }
    }

    cout << "! " << s << endl;

    return 0;
}