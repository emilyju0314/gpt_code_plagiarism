#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n < 3) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    cout << "0 0" << endl;
    cout << "1 0" << endl;
    cout << "0 1" << endl;

    for(int i = 3; i < n; i++) {
        cout << i-1 << " " << i-2 << endl;
    }
    
    return 0;
}