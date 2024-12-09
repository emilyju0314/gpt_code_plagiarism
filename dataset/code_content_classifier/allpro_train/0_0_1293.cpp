#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> createAbacusRow(int num) {
    vector<string> abacus(8, "***** *****");
    string numStr = to_string(num);
    
    for (int i = 0; i < numStr.size(); i++) {
        int digit = numStr[i] - '0';
        int rowIndex = 7 - digit;
        
        abacus[rowIndex][i] = '=';
    }
    
    return abacus;
}

int main() {
    int n;
    cin >> n;
    
    while (n--) {
        int num;
        cin >> num;
        
        vector<string> abacusRow = createAbacusRow(num);
        
        for (string bead : abacusRow) {
            cout << bead << endl;
        }
        
        cout << endl;
    }
    
    return 0;
}