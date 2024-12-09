#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string smallestPermutation(string S, string T) {
    string S_prime = "";
    vector<int> count(3, 0);
    
    for(char c : S) {
        if(c == T[0] && count[0] < count[1] + count[2]) {
            S_prime += c;
            count[0]++;
        } else if(c == T[1] && count[1] < count[2]) {
            S_prime += c;
            count[1]++;
        } else if(c == T[2]) {
            S_prime += c;
            count[2]++;
        }
    }
    
    return S_prime;
}

int main() {
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++) {
        string S, T;
        cin >> S >> T;
        
        string result = smallestPermutation(S, T);
        cout << result << endl;
    }
    
    return 0;
}