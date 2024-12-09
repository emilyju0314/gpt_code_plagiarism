#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    if (a[n-1] == 15 && a[n-2] == 0) {
        cout << "UP" << endl;
    } else if (a[n-1] == 0 && a[n-2] == 15) {
        cout << "DOWN" << endl;
    } else if (a[n-1] > a[n-2]) {
        cout << "UP" << endl;
    } else if (a[n-1] < a[n-2]) {
        cout << "DOWN" << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}