#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    cout << 3 * n + 4 << endl;
    cout << "0 0" << endl;
    cout << "1 0" << endl;
    cout << "2 0" << endl;
    
    int x = 0, y = 1;
    for (int i = 0; i < n; i++) {
        cout << x << " " << y << endl;
        cout << x+1 << " " << y << endl;
        cout << x+2 << " " << y << endl;
        
        x++;
        y++;
    }
    
    cout << x << " " << y << endl;
    cout << x+1 << " " << y << endl;
    cout << x+2 << " " << y << endl;

    return 0;
}