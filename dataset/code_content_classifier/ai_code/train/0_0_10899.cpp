#include <iostream>

using namespace std;

int main() {
    int H, R;
    cin >> H >> R;
    
    if (H > R) {
        cout << "1" << endl;
    } else if (R >= abs(H) && H < 0) {
        cout << "0" << endl;
    } else {
        cout << "-1" << endl;
    }
    
    return 0;
}