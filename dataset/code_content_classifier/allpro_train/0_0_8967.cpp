#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m, x;
    cin >> n;
    
    string crossword;
    cin >> crossword;
    
    cin >> m;
    vector<pair<string, int>> words(m);
    for (int i = 0; i < m; i++) {
        cin >> words[i].first >> words[i].second;
    }
    
    cin >> x;
    
    int maxPoints = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string word = words[j].first;
            int points = words[j].second;
            
            if (i + word.length() <= n) {
                int count = 0;
                for (int k = 0; k < word.length(); k++) {
                    if (crossword[i+k] != word[k]) {
                        break;
                    }
                    count++;
                }
                
                if (count == word.length()) {
                    int totalCount = 1;
                    for (int l = i + word.length(); l <= n - word.length(); l++) {
                        bool found = true;
                        for (int k = 0; k < word.length(); k++) {
                            if (crossword[l+k] != word[k]) {
                                found = false;
                                break;
                            }
                        }
                        if (found) {
                            totalCount++;
                        }
                        if (totalCount > x) {
                            break;
                        }
                    }
                    maxPoints = max(maxPoints, totalCount * points);
                }
            }
        }
    }
    
    cout << maxPoints << endl;

    return 0;
}