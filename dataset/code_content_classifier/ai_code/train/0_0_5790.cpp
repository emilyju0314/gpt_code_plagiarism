#include <iostream>
#include <vector>
using namespace std;

void printRectangle(int x1, int y1, int x2, int y2) {
    cout << x1 << " " << y1 << endl;
    cout << x2 << " " << y1 << endl;
    cout << x2 << " " << y2 << endl;
    cout << x1 << " " << y2 << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int dx = x2 - x1;
        int dy = y2 - y1;
        
        cout << dx + dy + 2 << endl;
        if (dx < 0) {
            swap(x1, x2);
            dx = x2 - x1;
        }
        if (dy < 0) {
            swap(y1, y2);
            dy = y2 - y1;
        }
        
        if (dx > 0 && dy > 0) {
            printRectangle(x1, y1, x2, y2);
            cout << x2 << " " << y1 << endl;
            cout << x1 << " " << y2 << endl;
        } else if (dx > 0) {
            cout << x2 << " " << y1 << endl;
            cout << x1 << " " << y1 << endl;
        } else if (dy > 0) {
            cout << x1 << " " << y2 << endl;
            cout << x1 << " " << y1 << endl;
        } else {
            cout << x1 << " " << y1 << endl;
        }
    }
    
    return 0;
}