#include <iostream>
using namespace std;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    
    int totalLength = X - Z;
    int seatLength = Y + Z;
    
    int maxPeople = totalLength / seatLength;
    
    cout << maxPeople << endl;
    
    return 0;
}