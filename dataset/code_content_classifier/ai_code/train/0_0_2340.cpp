#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    
    int count = 0;
    while (true) {
        string newS = "";
        for (char c : s) {
            newS += c;
            if (newS.size() >= t.size() && newS.substr(newS.size() - t.size()) == t) {
                newS.erase(newS.size() - t.size());
                count++;
            }
        }
        
        if (newS == s) {
            break;
        }
        
        s = newS;
    }
    
    cout << count << endl;
    
    return 0;
}