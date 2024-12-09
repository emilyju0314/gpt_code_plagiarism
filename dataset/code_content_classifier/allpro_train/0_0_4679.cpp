#include <iostream>
#include <string>

using namespace std;

bool isClassy(int x) {
    string s = to_string(x);
    int count = 0;
    for(char c : s) {
        if(c != '0') {
            count++;
        }
    }
    return count <= 3;
}

int countClassyIntegers(int L, int R) {
    int count = 0;
    for(int i = L; i <= R; i++) {
        if(isClassy(i)) {
            count++;
        }
    }
    return count;
}

int main() {
    int T;
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        int L, R;
        cin >> L >> R;
        
        cout << countClassyIntegers(L, R) << endl;
    }
    
    return 0;
}