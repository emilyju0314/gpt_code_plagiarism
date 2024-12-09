#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    
    cin >> N >> S;
    
    for(int i = 0; i < S.length(); i++) {
        char c = S[i];
        if(c + N > 'Z') {
            S[i] = 'A' + (c + N - 'Z' - 1);
        } else {
            S[i] = c + N;
        }
    }
    
    cout << S << endl;
    
    return 0;
}