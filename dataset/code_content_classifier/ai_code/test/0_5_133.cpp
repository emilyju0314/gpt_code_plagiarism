#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<string> bigrams(n-2);
        for(int i = 0; i < n-2; i++) {
            cin >> bigrams[i];
        }
        
        string first, second;
        for(int i = 0; i < n-2; i++) {
            if(bigrams[i] == bigrams[i+1]) {
                first = bigrams[i];
                second = bigrams[i+1];
                break;
            }
        }
        
        string word = first + second[1];
        cout << word << endl;
    }
    
    return 0;
}