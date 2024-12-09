#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    vector<int> count(n+1, 0);
    
    for (int i = 1; i <= n; i++) {
        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            a[j] = i;
        }

        cout << "? ";
        for (int j = 0; j < n; j++) {
            cout << a[j] << " ";
        }
        cout << endl;
        
        int k;
        cin >> k;
        if (k == 0) {
            cout << "! ";
            for (int j = 0; j < n; j++) {
                cout << p[j] << " ";
            }
            cout << endl;
            cout.flush();
            return 0;
        }
        
        for (int j = 0; j < n; j++) {
            p[j] = i + a[j];
        }
        count[k]++;
        
        if (count[k] == 2) {
            for (int j = 0; j < n; j++) {
                if (p[j] == k) {
                    p[j] = i;
                    break;
                }
            }
        }
    }
    
    cout << "! ";
    for (int j = 0; j < n; j++) {
        cout << p[j] << " ";
    }
    cout << endl;
    cout.flush();

    return 0;
}