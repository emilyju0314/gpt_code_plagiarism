#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        a[i] = i + 1;
    }

    for(int i = 0; i < n; i++) {
        vector<int> s(n);
        cout << "? ";
        for(int j = 0; j < n; j++) {
            cout << a[j] << " ";
            s[j] = p[j] + a[j];
        }
        cout << endl;
        
        int k;
        cin >> k;

        if(k == 0) {
            break;
        }

        k--;
        p[k] = s[k] - a[k];
    }

    cout << "! ";
    for(int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;

    return 0;
}