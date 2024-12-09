#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> spoilt(n);
    for (int i = 0; i < n; i++) {
        cin >> spoilt[i];
    }

    int l = -1, r = -1;
    
    for (int i = 0; i < n-1; i++) {
        if (spoilt[i] > spoilt[i+1]) {
            l = i;
            break;
        }
    }
    
    for (int i = n-1; i > 0; i--) {
        if (spoilt[i] < spoilt[i-1]) {
            r = i;
            break;
        }
    }
    
    if (l == -1 && r == -1) {
        cout << "0 0" << endl;
    } else {
        reverse(spoilt.begin() + l, spoilt.begin() + r + 1);
        bool sorted = true;
        for (int i = 0; i < n-1; i++) {
            if (spoilt[i] > spoilt[i+1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            cout << l+1 << " " << r+1 << endl;
        } else {
            cout << "0 0" << endl;
        }
    }

    return 0;
}