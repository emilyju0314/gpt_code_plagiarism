#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string sequence;
    cin >> n >> sequence;
    
    int U = 0, D = 0, L = 0, R = 0;
    
    for(char command : sequence) {
        if(command == 'U') {
            U++;
        } else if(command == 'D') {
            D++;
        } else if(command == 'L') {
            L++;
        } else if(command == 'R') {
            R++;
        }
    }
    
    int minUD = min(U, D);
    int minLR = min(L, R);
    
    cout << 2 * (minUD + minLR) << endl;
    
    return 0;
}