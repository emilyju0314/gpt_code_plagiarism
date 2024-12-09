#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string S, T;
    cin >> S >> T;
    
    int Q;
    cin >> Q;
    
    for (int i = 0; i < Q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        vector<int> occurrences_S(3, 0);
        vector<int> occurrences_T(3, 0);
        for (int j = a-1; j < b; j++) {
            if (S[j] == 'A') occurrences_S[0]++;
            else if (S[j] == 'B') occurrences_S[1]++;
            else occurrences_S[2]++;
        }
        for (int j = c-1; j < d; j++) {
            if (T[j] == 'A') occurrences_T[0]++;
            else if (T[j] == 'B') occurrences_T[1]++;
            else occurrences_T[2]++;
        }
        
        int diff_A = occurrences_T[0] - occurrences_S[0];
        int diff_B = occurrences_T[1] - occurrences_S[1];
        int diff_C = occurrences_T[2] - occurrences_S[2];
        
        if (diff_A < 0 || diff_B < 0 || diff_C < 0) {
            cout << "0";
        } else if ((diff_A + diff_B + diff_C) % 3 == 0) {
            cout << "1";
        } else {
            cout << "0";
        }
    }
    
    cout << endl;
    
    return 0;
}