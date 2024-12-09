#include <iostream>
using namespace std;

int main() {
    int N, M, caseNum = 1;
    
    while (true) {
        cin >> N >> M;
        
        if (N == 0 && M == 0) {
            break;
        }
        
        int turns = 1;
        int players = 1;
        
        while (true) {
            if (players >= N) {
                cout << "Case " << caseNum << ": " << turns << endl;
                break;
            }
            
            players *= M;
            turns++;
        }
        
        caseNum++;
    }
    
    return 0;
}