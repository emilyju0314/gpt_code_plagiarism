#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int minOperations(string S, string T) {
    int operations = 0;
    int n = S.length();
    
    while (S != T) {
        int index = S.find_last_of('1');
        if (S[index-1] == T[index-1]) {
            S[index] = T[index];
        } else if (S[index-1] == '0') {
            S[index-1] = '1';
            operations++;
        } else {
            S[index-1] = '0';
            operations++;
        }
    }
    
    return operations;
}

int main() {
    int Q;
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        string S, T;
        cin >> S >> T;
        
        cout << minOperations(S, T) << endl;
    }
    
    return 0;
}