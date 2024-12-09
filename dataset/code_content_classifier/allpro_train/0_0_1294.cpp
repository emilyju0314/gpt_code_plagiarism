#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    
    while (true) {
        cin >> input;
        
        if (input == "#") {
            break;
        }
        
        int currentCity = 0;
        bool validRoute = true;
        
        for (char c : input) {
            if (c == '0') {
                currentCity = currentCity * 2 + 1;
            } else {
                currentCity = currentCity * 2 + 2;
            }
            
            if (currentCity == 11 || currentCity == 13 || currentCity == 14) {
                validRoute = false;
                break;
            }
        }
        
        if (validRoute && currentCity == 8) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}