#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string x;
        cin >> x;

        vector<char> a(n, '0');
        vector<char> b(n, '0');

        bool switch_b = false;
        for(int i = 1; i < n; i++) {
            if(x[i] == '0') {
                a[i] = '0';
                b[i] = '0';
            } else if(x[i] == '1') {
                a[i] = '1';
                b[i] = '0';
                if(!switch_b) {
                    switch_b = true;
                    swap(a[i], b[i]);
                }
            } else if(x[i] == '2') {
                if(switch_b) {
                    a[i] = '0';
                    b[i] = '2';
                } else {
                    a[i] = '1';
                    b[i] = '1';
                }
            }
        }

        a[0] = '1';
        b[0] = '1';
        for(int i = 0; i < n; i++) {
            cout << a[i];
        }
        cout << endl;

        for(int i = 0; i < n; i++) {
            cout << b[i];
        }
        cout << endl;
    }

    return 0;
}