#include <iostream>

using namespace std;

int main() {
    int k;
    cin >> k;
    
    cout << "+------------------------+" << endl;
    cout << "|";
    
    for (int i = 0; i < 11; i++) {
        if (i < k) {
            if (i % 3 == 2) {
                cout << ".|";
            } else {
                cout << "O.";
            }
        } else {
            cout << "#.";
        }
    }
    
    cout << "|D|)" << endl;
    
    cout << "|";
    
    for (int i = 0; i < 11; i++) {
        if (i < k - 11) {
            if (i % 3 == 2) {
                cout << ".|";
            } else {
                cout << "O.";
            }
        } else {
            cout << "#.";
        }
    }
    
    cout << "|" << endl;
    cout << "|O.......................|" << endl;
    cout << "|";
    
    for (int i = 0; i < 11; i++) {
        if (i < k % 11) {
            if (i % 3 == 2) {
                cout << ".|";
            } else {
                cout << "O.";
            }
        } else {
            cout << "#.";
        }
    }
    
    cout << "|D|)" << endl;
    cout << "+------------------------+" << endl;

    return 0;
}