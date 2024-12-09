#include <iostream>
#include <string>

using namespace std;

int countOnes(string binary) {
    int count = 0;
    for (char c : binary) {
        if (c == '1') count++;
    }
    return count;
}

int main() {
    int N;
    string A, B;
    
    cin >> N >> A >> B;
    
    for (int i = 0; i < N; i++) {
        char type;
        int index;
        
        cin >> type >> index;
        
        if (type == 'Q') {
            string maxBinary = A;
            for (int j = 0; j < A.size(); j++) {
                if (A[j] == '0' && B[j] == '1') {
                    maxBinary[j] = '1';
                }
            }
            cout << countOnes(maxBinary) << endl;
        } else if (type == 'A') {
            A[index] = (A[index] == '0') ? '1' : '0';
        } else if (type == 'B') {
            B[index] = (B[index] == '0') ? '1' : '0';
        }
    }
    
    return 0;
}