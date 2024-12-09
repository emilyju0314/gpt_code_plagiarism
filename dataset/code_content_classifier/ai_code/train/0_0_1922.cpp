#include <iostream>
#include <vector>

using namespace std;

int main() {
    string binary;
    cin >> binary;
    
    int n = binary.size();
    vector<int> powers;
    
    for (int i = 0; i < n; i++) {
        if (binary[i] == '1') {
            powers.push_back(n - i - 1);
        }
    }
    
    cout << powers.size() << endl;
    for (int power : powers) {
        if (power == 0) {
            cout << "-2^0" << endl;
        } else {
            cout << "+2^" << power << endl;
        }
    }
    
    return 0;
}