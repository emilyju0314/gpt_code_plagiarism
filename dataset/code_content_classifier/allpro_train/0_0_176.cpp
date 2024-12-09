#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isGoodString(const string& s) {
    int count_0 = 0, count_1 = 0;
    for(char c : s) {
        if(c == '0') {
            count_0++;
        } else {
            count_1++;
        }
    }
    return count_0 != count_1;
}

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    vector<string> substrings;
    string current;
    for(char c : s) {
        current += c;
        if(isGoodString(current)) {
            substrings.push_back(current);
            current = "";
        }
    }
    
    cout << substrings.size() << endl;
    for(const string& sub : substrings) {
        cout << sub << " ";
    }
    
    return 0;
}