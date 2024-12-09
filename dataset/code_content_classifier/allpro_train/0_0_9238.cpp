#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string moves;
    
    cin >> n;
    cin >> moves;
    
    int length = n;
    
    for (int i = 0; i < n - 1; i++) {
        if ((moves[i] == 'R' && moves[i+1] == 'U') || (moves[i] == 'U' && moves[i+1] == 'R')) {
            length--;
            i++;
        }
    }
    
    cout << length << endl;
    
    return 0;
}