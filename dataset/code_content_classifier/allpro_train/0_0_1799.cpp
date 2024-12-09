#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool canBeMadeEqual(string S, string T) {
    if(S.size() != T.size()) {
        return false;
    }
    
    unordered_map<char, char> mapping;
    
    for(int i = 0; i < S.size(); i++) {
        if(mapping.find(S[i]) == mapping.end()) {
            mapping[S[i]] = T[i];
        } else {
            if(mapping[S[i]] != T[i]) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    string S, T;
    cin >> S >> T;
    
    if(canBeMadeEqual(S, T)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}