#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    
    string S;
    cin >> S;
    
    vector<int> freq(N, 0);
    for (int i = 1; i < N; i++) {
        freq[i] = freq[i - 1];
        if (S[i - 1] == 'A' && S[i] == 'C') {
            freq[i]++;
        }
    }
    
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        
        cout << freq[r - 1] - freq[l - 1] << endl;
    }
    
    return 0;
}