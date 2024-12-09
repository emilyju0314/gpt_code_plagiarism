#include<bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    
    int count = 0;
    char current = 'A';
    
    for(int i = 0; i < S.length(); i++) {
        int steps = ((S[i] - 'A') + 26 - (current - 'A')) % 26;
        count += steps;
        current = S[i];
    }
    
    cout << count << endl;
    
    return 0;
}