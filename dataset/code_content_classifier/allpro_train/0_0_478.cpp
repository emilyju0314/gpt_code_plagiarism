#include <iostream>

using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    
    int a[n], b[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    bool lie = true;
    for(int i = 0; i < l-1; i++) {
        if(a[i] != b[i]) {
            lie = false;
        }
    }
    for(int i = r; i < n; i++) {
        if(a[i] != b[i]) {
            lie = false;
        }
    }

    if(lie) {
        cout << "TRUTH" << endl;
    } else {
        cout << "LIE" << endl;
    }

    return 0;
}