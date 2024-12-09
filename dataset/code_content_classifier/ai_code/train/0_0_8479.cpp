#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string S;
    cin >> S;

    int n = S.length();
    int count = 0;

    for (int i = 0; i < n/2; i++) {
        if (S[i] != S[n-1-i]) {
            int j = i + 1;
            while (S[j] != S[n-1-i]) {
                j++;
            }
            if (j == n) {
                cout << -1 << endl;
                return 0;
            }
            while (j > i) {
                swap(S[j], S[j-1]);
                j--;
                count++;
            }
        }
    }

    cout << count << endl;
    
    return 0;
}