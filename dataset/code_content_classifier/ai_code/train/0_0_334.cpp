#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isLexicographical(vector<string>& words) {
    for (int i = 0; i < words.size() - 1; i++) {
        if (words[i] > words[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        
        vector<string> words(n);
        for (int i = 0; i < n; i++) {
            cin >> words[i];
        }
        
        if (isLexicographical(words)) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    
    return 0;
}