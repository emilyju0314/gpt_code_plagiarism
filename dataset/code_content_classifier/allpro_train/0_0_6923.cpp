#include <iostream>
#include <vector>
using namespace std;

bool canWin(int P, const vector<int>& G, int A) {
    int current = 1;
    
    for(int i = 0; i < G.size(); i++) {
        int new_num = (current * G[i]) % P; // perform the operation described in the problem
        if(new_num == A) {
            return true;
        }
        current = new_num;
    }
    
    return false;
}

int main() {
    int P, T;
    cin >> P >> T;
    
    for(int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<int> G(N);
        int A;
        
        for(int j = 0; j < N; j++) {
            cin >> G[j];
        }
        cin >> A;
        
        if(canWin(P, G, A)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    
    return 0;
}