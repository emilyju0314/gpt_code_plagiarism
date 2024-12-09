#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string positions;
    
    cin >> n;
    cin >> positions;
    
    int cnt = 0;
    for(char c : positions) {
        if(c == 'X') {
            cnt++;
        }
    }
    
    int minutes = abs(cnt - n/2);
    
    cout << minutes << endl;
    
    if(cnt > n/2) {
        for(int i = 0; i < n/2; i++) {
            cout << 'x';
        }
        for(int i = 0; i < n/2; i++) {
            cout << 'X';
        }
    } else {
        for(int i = 0; i < n/2; i++) {
            cout << 'X';
        }
        for(int i = 0; i < n/2; i++) {
            cout << 'x';
        }
    }
    
    return 0;
}