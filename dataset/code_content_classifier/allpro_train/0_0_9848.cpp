#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int num_flipped = 0;
    
    for(int i=0; i<s.length(); i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            if(s[i+1] != '0' && s[i+1] != '2' && s[i+1] != '4' && s[i+1] != '6' && s[i+1] != '8') {
                num_flipped++;
            }
        }
    }
    
    cout << num_flipped << endl;
    
    return 0;
}