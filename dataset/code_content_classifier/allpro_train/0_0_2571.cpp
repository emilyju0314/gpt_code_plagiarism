#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    
    cin >> n;
    cin >> s;
    
    string result = "";
    
    for(int i = 0; i < n; i++) {
        if(result.size() >= 2 && islower(s[i]) && (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y') && (result[result.size()-1] == 'a' || result[result.size()-1] == 'e' || result[result.size()-1] == 'i' || result[result.size()-1] == 'o' || result[result.size()-1] == 'u' || result[result.size()-1] == 'y')) {
            result.pop_back();
        }
        
        result += s[i];
    }
    
    cout << result << endl;
    
    return 0;
}