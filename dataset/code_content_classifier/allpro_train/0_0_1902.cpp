#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, D;
    string X;
    cin >> N >> X >> D;
    
    for (int i = 0; i < N; i++) {
        if (D > 0 && X[i] == '0') {
            cout << '1';
            D--;
        } else {
            cout << X[i];
        }
    }
    
    cout << endl;
    
    return 0;
}