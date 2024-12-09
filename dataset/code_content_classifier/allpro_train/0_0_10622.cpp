#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string getExpression(string truthTable) {
    if(truthTable[0] == '0' && truthTable[1] == '0' && truthTable[2] == '1' && truthTable[3] == '1' && truthTable[4] == '0' && truthTable[5] == '0' && truthTable[6] == '1' && truthTable[7] == '1') {
        return "y";
    } else if(truthTable[0] == '0' && truthTable[1] == '0' && truthTable[2] == '0' && truthTable[3] == '0' && truthTable[4] == '0' && truthTable[5] == '1' && truthTable[6] == '1' && truthTable[7] == '1') {
        return "(y|z)&x";
    } else if(truthTable[0] == '1' && truthTable[1] == '1' && truthTable[2] == '1' && truthTable[3] == '1' && truthTable[4] == '0' && truthTable[5] == '0' && truthTable[6] == '0' && truthTable[7] == '0') {
        return "!x";
    } else {
        return "x|y&z";
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<string> truthTables(n);
    for(int i = 0; i < n; i++) {
        cin >> truthTables[i];
    }
    
    for(int i = 0; i < n; i++) {
        cout << getExpression(truthTables[i]) << endl;
    }
    
    return 0;
}