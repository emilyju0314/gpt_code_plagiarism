#include <iostream>
#include <cmath>

using namespace std;

int main() {
    string handle;
    cin >> handle;
    
    int length = handle.length();
    int rows = ceil((double)length / 20);
    int cols = ceil((double)length / rows);
    
    cout << rows << " " << cols << endl;
    
    int currentPos = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (currentPos < length) {
                cout << handle[currentPos++];
            } else {
                cout << "*";
            }
        }
        cout << endl;
    }
    
    return 0;
}