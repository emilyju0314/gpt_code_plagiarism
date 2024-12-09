#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    string actions[n];
    
    for(int i=0; i<n; i++) {
        cin >> actions[i];
    }
    
    char selected_letter = actions[n-1][2];
    
    int shocks_avoided = 0;
    bool determined = false;
    set<char> possible_letters;
    
    for(int i=0; i<n-1; i++) {
        if(actions[i][0] == '!') {
            possible_letters.insert(actions[i][2]);
            if(possible_letters.size() == 1 && actions[i][2] != selected_letter) {
                determined = true;
            }
        } else if(actions[i][0] == '.') {
            if(possible_letters.find(selected_letter) == possible_letters.end()) {
                shocks_avoided++;
            }
        } else {
            if(determined && actions[i][2] == selected_letter) {
                break;
            }
        }
    }
    
    cout << shocks_avoided << endl;
    
    return 0;
}