#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    string s;
    cin >> s;
    
    unordered_set<string> substrings;
    unordered_map<int, int> letter_counts;
    
    for(int i=0; i<n; i++) {
        letter_counts[s[i]]++;
    }
    
    substrings.insert(s);
    
    int left = 0, right = n-1;
    for(int i=0; i<m; i++) {
        string query;
        cin >> query;
        
        if(query == "L++") {
            left++;
        } else if(query == "L--") {
            left--;
        } else if(query == "R++") {
            right++;
        } else if(query == "R--") {
            right--;
        }
        
        if(left == 0 && right == n-1) {
            substrings.insert(s);
        } else if(left == 0) {
            letter_counts[s[right+1]]++;
            if(letter_counts[s[right+1]] == 1){
                substrings.insert(s.substr(right+1, n-right-1));
            }
        } else if(right == n-1) {
            letter_counts[s[left-1]]++;
            if(letter_counts[s[left-1]] == 1) {
                substrings.insert(s.substr(0, left));
            }
        } else {
            letter_counts[s[right+1]]++;
            if(letter_counts[s[right+1]] == 1) {
                substrings.insert(s.substr(right+1, n-right-1));
            }
            
            letter_counts[s[left-1]]++;
            if(letter_counts[s[left-1]] == 1) {
                substrings.insert(s.substr(0, left));
            }
        }
        
        s = s.substr(left, right-left+1);
    }
    
    cout << substrings.size() << endl;
    
    return 0;
}