#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N;
    string S;
    
    cin >> N >> S;
    
    int x = 0;
    int max_x = 0;
    
    for(int i = 0; i < N; i++) {
        if(S[i] == 'I') {
            x++;
        } else {
            x--;
        }
        max_x = max(max_x, x);
    }
    
    cout << max_x << endl;
    
    return 0;
}