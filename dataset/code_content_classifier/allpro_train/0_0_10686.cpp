#include <iostream>
#include <vector>
using namespace std;

bool canReconstructWords(vector<int>& wordLengths) {
    for(int i=0; i<wordLengths.size()-1; i++) {
        if(wordLengths[i] >= wordLengths[i+1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> wordLengths(N);
    for(int i=0; i<N; i++) {
        cin >> wordLengths[i];
    }
    
    if(canReconstructWords(wordLengths)) {
        cout << "YES" << endl;
        for(int i=0; i<N; i++) {
            for(int j=0; j<wordLengths[i]; j++) {
                cout << j%2;
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}