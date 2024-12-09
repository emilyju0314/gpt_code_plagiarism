#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isGoodString(vector<string> &set, string perm) {
    for(string str : set) {
        size_t found = perm.find(str);
        if (found == string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> set(n);
    
    for(int i=0; i<n; i++) {
        cin >> set[i];
    }
    
    sort(set.begin(), set.end());
    
    string minGoodString = "";
    string currentString = "";
    
    do {
        currentString = "";
        for(string s : set) {
            currentString += s;
        }
        
        if (isGoodString(set, currentString)) {
            if (minGoodString == "" || currentString < minGoodString) {
                minGoodString = currentString;
            }
        }
    } while(next_permutation(set.begin(), set.end()));
    
    if (minGoodString == "") {
        cout << "NO" << endl;
    } else {
        cout << minGoodString << endl;
    }
    
    return 0;
}