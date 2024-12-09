#include <iostream>
#include <string>

using namespace std;

string correctTypos(string word) {
    string result = "";
    
    for (int i = 0; i < word.length(); i++) {
        if (i > 1 && word[i] == word[i-1] && word[i-1] == word[i-2]) {
            continue;
        } else if (i > 3 && word[i] == word[i-1] && word[i-2] == word[i-3]) {
            continue;
        } else {
            result += word[i];
        }
    }
    
    return result;
}

int main() {
    string word;
    cin >> word;
    
    cout << correctTypos(word) << endl;
    
    return 0;
}