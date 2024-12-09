#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    sort(s.begin(), s.end());
    
    for(char c : t){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == c){
                cout << s[i];
                s.erase(s.begin() + i);
                break;
            }
        }
    }
    
    cout << s << endl;

    return 0;
}