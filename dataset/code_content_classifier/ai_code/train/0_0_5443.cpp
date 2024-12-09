#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int L, Q;
    cin >> L >> Q;
    
    string S;
    cin >> S;
    
    vector<int> viperToxicity(1 << L);
    for(int i = 0; i < (1 << L); i++) {
        viperToxicity[i] = S[i] - '0';
    }
    
    for(int day = 0; day < Q; day++) {
        string complaint;
        cin >> complaint;
        
        int totalToxicity = 0;
        for(int i = 0; i < (1 << L); i++) {
            bool escape = true;
            for(int j = 0; j < L; j++) {
                if(complaint[j] == '0' && ((i >> j) & 1) != 0) {
                    escape = false;
                    break;
                }
                if(complaint[j] == '1' && ((i >> j) & 1) != 1) {
                    escape = false;
                    break;
                }
            }
            if(escape) {
                totalToxicity += viperToxicity[i];
            }
        }
        
        cout << totalToxicity << endl;
    }
    
    return 0;
}