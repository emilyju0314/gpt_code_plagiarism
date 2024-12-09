#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string row;
    bool hasS = false;
    
    for (int i = 0; i < n; i++) {
        cin >> row;
        if (row.find("SSS") != string::npos) {
            hasS = true;
            break;
        }
    }
    
    if (hasS) {
        cout << "Hanako" << endl;
    } else {
        cout << "Taro" << endl;
    }
    
    return 0;
}