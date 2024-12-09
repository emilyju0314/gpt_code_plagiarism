#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string S;
    cin >> S;
    
    int n = S.length();
    int zeros = 0, ones = 0;
    int max_diff = 0;
    
    for(int i = 0; i < n; i++) {
        if(S[i] == '0') {
            zeros++;
        } else if(S[i] == '1') {
            ones++;
        }
        max_diff = max(max_diff, abs(zeros - ones));
    }
    
    cout << max_diff << endl;
    
    return 0;
}