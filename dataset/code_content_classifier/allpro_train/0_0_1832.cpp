#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        
        vector<int> indicesToRemove;
        int count = 0;
        for(int i=0; i<s.length(); i++) {
            if(i+2 < s.length() && s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e') {
                indicesToRemove.push_back(i+2);
                i += 2;
                count++;
            } else if(i+2 < s.length() && s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o') {
                indicesToRemove.push_back(i+2);
                i += 2;
                count++;
            }
        }

        cout << count << endl;
        for(int i=0; i<count; i++) {
            cout << indicesToRemove[i] << " ";
        }
        cout << endl;
    }

    return 0;
}