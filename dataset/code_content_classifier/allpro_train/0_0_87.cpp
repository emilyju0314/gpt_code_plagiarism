#include <iostream>
#include <vector>

using namespace std;

int main() {
    int a = 0, b = 0;
    
    for (int i = 0; i < 30; i++) {
        cout << "? " << (1 << i) << " " << 0 << endl;
        cout.flush();
        
        int response;
        cin >> response;
        
        if (response == 1) {
            a |= (1 << i);
        } else if (response == -1) {
            b |= (1 << i);
        }
    }
    
    cout << "! " << a << " " << b << endl;
    
    return 0;
}