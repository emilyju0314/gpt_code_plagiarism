#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string S, T;
    cin >> n >> S >> T;
    
    int count = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        string W = "";
        for (int i = 0; i < n; i++) {
            if (S[i] == T[i] && S[i] == c) {
                W += c;
            } else if (S[i] == c || T[i] == c) {
                W += c;
            } else {
                W += S[i];
            }
        }
        
        if (W == S || W == T) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}