#include <iostream>
#include <string>

using namespace std;

int main() {
    int resistance = -1;
    
    for(int i = 1; i <= 302; i++) {
        string spell;
        for(int j = 0; j < i; j++) {
            spell += 'a';
        }
        
        cout << spell << endl;
        fflush(stdout);
        
        cin >> resistance;
        
        if(resistance == 0) {
            break;
        }
    }
    
    return 0;
}