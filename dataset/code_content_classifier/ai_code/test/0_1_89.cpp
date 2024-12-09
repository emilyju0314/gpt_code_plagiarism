#include <iostream>
#include <vector>

using namespace std;

bool eraseSequencePossible(vector<int>& sequence) {
    for(int i = 0; i < sequence.size(); i++) {
        if(sequence[i] % (i+1) != 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> sequence(n);
        for(int i = 0; i < n; i++) {
            cin >> sequence[i];
        }

        if(eraseSequencePossible(sequence)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}