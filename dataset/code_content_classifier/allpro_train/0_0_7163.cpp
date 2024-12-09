#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, Q;
    cin >> N;
    
    string S;
    cin >> S;
    
    cin >> Q;
    vector<char> arr(N);
    for(int i = 0; i < N; i++) {
        arr[i] = S[i];
    }
    
    unordered_set<char> uniqueChars;
    
    for(int i = 0; i < Q; i++) {
        int queryType, l, r;
        cin >> queryType >> l >> r;
        
        if(queryType == 1) {
            char c;
            cin >> c;
            arr[l-1] = c;
        } else if(queryType == 2) {
            uniqueChars.clear();
            for(int j = l-1; j < r; j++) {
                uniqueChars.insert(arr[j]);
            }
            cout << uniqueChars.size() << endl;
        }
    }
    
    return 0;
}