#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string str){
    int start = 0;
    int end = str.length() - 1;
    
    while(start < end){
        if(str[start] != str[end]){
            return false;
        }
        start++;
        end--;
    }
    
    return true;
}

int countPalindromicSubstrings(string s, int l, int r){
    int count = 0;
    
    for(int i = l-1; i <= r-1; i++){
        for(int j = i; j < r; j++){
            if(isPalindrome(s.substr(i, j-i+1))){
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    string s;
    cin >> s;
    
    int q;
    cin >> q;
    
    vector<pair<int, int>> queries(q);
    
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        queries[i] = make_pair(l, r);
    }
    
    vector<int> answers;
    for(int i = 0; i < q; i++){
        answers.push_back(countPalindromicSubstrings(s, queries[i].first, queries[i].second));
    }
    
    for(int i = 0; i < q; i++){
        cout << answers[i] << endl;
    }
    
    return 0;
}