#include <iostream>
#include <string>

using namespace std;

int main() {
    string T;
    cin >> T;
    
    int n = T.size();
    
    for(int i = 0; i < n; i++) {
        if(T[i] == '?') {
            if(i > 0 && T[i-1] == 'D') {
                T[i] = 'P';
            } else {
                T[i] = 'D';
            }
        }
    }
    
    cout << T << endl;
    
    return 0;
}