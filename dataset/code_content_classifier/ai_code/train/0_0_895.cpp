#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> letters(n);
    
    for (int i = 0; i < n; i++) {
        cin >> letters[i];
    }
    
    unordered_map<int, int> seen;
    vector<int> result;
    
    int i = 0;
    
    while(i < n) {
        int j = i;
        while(j + 1 < n && letters[j] != letters[j+1]) {
            j++;
        }
        
        if (j - i + 1 < 2) {
            result.push_back(letters[i]);
            i++;
        } else {
            if (seen.find(letters[i]) == seen.end() || seen[letters[i]] < 1) {
                if (seen.find(letters[i]) == seen.end()) {
                    seen[letters[i]] = 1;
                } else {
                    seen[letters[i]]++;
                }
                result.push_back(letters[i]);
            } else {
                seen[letters[i]]--;
            }
            i = j + 2;
        }
    }
    
    cout << result.size() << endl;
    for (int val : result) {
        cout << val << " ";
    }
    
    return 0;
}