#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string phoneNumber;
    cin >> phoneNumber;
    
    int i = 0;
    while (i < n) {
        if (n - i >= 4) {
            cout << phoneNumber.substr(i, 2) << "-";
            i += 2;
        } else {
            cout << phoneNumber.substr(i, 3);
            i += 3;
            if (i < n) {
                cout << "-";
            }
        }
    }
    
    return 0;
}