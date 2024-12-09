#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> coefficients(11);
    
    for (int i = 0; i <= 10; i++) {
        cin >> coefficients[i];
    }

    for (int x = 0; x < 10^6 + 3; x++) {
        cout << "? " << x << endl;
        cout.flush();
        
        int result;
        cin >> result;
        
        if (result == 0) {
            cout << "! " << x << endl;
            return 0;
        }        
    }

    cout << "! -1" << endl;
    
    return 0;
}