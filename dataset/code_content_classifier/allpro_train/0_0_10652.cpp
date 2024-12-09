#include <iostream>
using namespace std;

int main() {
    int x;
    int caseNum = 1;
    
    while (true) {
        cin >> x;
        
        if (x == 0) {
            break;
        }
        
        cout << "Case " << caseNum << ": " << x << endl;
        
        caseNum++;
    }
    
    return 0;
}