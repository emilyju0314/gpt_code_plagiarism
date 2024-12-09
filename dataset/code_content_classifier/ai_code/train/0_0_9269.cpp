#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i += 2) {
        cout << "? " << i << endl;
        fflush(stdout);
        
        int num1;
        cin >> num1;
        
        cout << "? " << (i + n/2) << endl;
        fflush(stdout);
        
        int num2;
        cin >> num2;
        
        if (num1 == num2) {
            cout << "! " << i << endl;
            return 0;
        }
    }
    
    cout << "! -1" << endl;
    
    return 0;
}