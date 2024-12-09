#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    
    cin >> N >> S;
    
    int count = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (S[i] != S[j] && S[i] != S[k] && S[j] != S[k] && j - i != k - j) {
                    count++;
                }
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}