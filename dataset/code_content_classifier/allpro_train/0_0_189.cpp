#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minChangesToAvoidPalindromes(string& poem) {
    int changes = 0;
    for(int i = 0; i < poem.size(); i++) {
        if(i > 0 && poem[i] == poem[i-1]) {
            changes++;
            if(i < poem.size()-1 && poem[i] != poem[i+1]) {
                poem[i] = ' ';
            } else {
                poem[i] = (poem[i] == 'a') ? 'b' : 'a';
            }
        }
    }
    return changes;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        string poem;
        cin >> poem;
        
        int changes = minChangesToAvoidPalindromes(poem);
        cout << changes << endl;
    }

    return 0;
}