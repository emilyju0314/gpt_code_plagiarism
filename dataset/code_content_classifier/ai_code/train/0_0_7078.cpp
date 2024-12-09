#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    string S;
    int Q;
    cin >> N >> S >> Q;

    vector<int> k_values(Q);
    for(int i = 0; i < Q; i++) {
        cin >> k_values[i];
    }

    vector<int> dmc_count(Q, 0);

    for(int i = 0; i < Q; i++) {
        int k = k_values[i];
        for(int a = 0; a < N-2; a++) {
            if(S[a] == 'D') {
                for(int b = a+1; b < N-1; b++) {
                    if(S[b] == 'M') {
                        for(int c = b+1; c < N; c++) {
                            if(S[c] == 'C' && c-a < k) {
                                dmc_count[i]++;
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < Q; i++) {
        cout << dmc_count[i] << endl;
    }

    return 0;
}