#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    
    string S;
    cin >> S;
    
    int passed_Japanese = 0;
    int passed_overseas = 0;
    
    for (int i = 0; i < N; i++) {
        if (S[i] == 'a') {
            if (passed_Japanese < A + B) {
                cout << "Yes" << endl;
                passed_Japanese++;
            } else {
                cout << "No" << endl;
            }
        } else if (S[i] == 'b') {
            if (passed_Japanese + passed_overseas < A + B) {
                cout << "Yes" << endl;
                passed_overseas++;
            } else {
                cout << "No" << endl;
            }
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}