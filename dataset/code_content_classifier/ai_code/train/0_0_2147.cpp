#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;
    
    // Check if Takahashi's age matches the criteria for Shichi-Go-San
    if(X == 3 || X == 5 || X == 7) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}