#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int m;
    cin >> m;
    
    vector<string> beautiful_words(m);
    for(int i = 0; i < m; i++) {
        cin >> beautiful_words[i];
    }
    
    int count = 0;
    
    for(int i = 0; i < m; i++) {
        string word = beautiful_words[i];
        
        bool possible = false;
        
        for(int a = 0; a < s.length() - word.length() + 1; a++) {
            for(int b = a + 1; b < s.length(); b++) {
                for(int c = b + 1; c < s.length() - word.length() + 1; c++) {
                    for(int d = c + 1; d < s.length(); d++) {
                        string potential_word = s.substr(a, b - a + 1) + s.substr(c, d - c + 1);
                        if(potential_word.find(word) != string::npos) {
                            possible = true;
                            break;
                        }
                    }
                    if(possible) break;
                }
                if(possible) break;
            }
            if(possible) break;
        }
        
        if(possible) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}