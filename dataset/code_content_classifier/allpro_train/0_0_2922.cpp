#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> C(N-1), S(N-1), F(N-1);
    for(int i = 0; i < N-1; i++) {
        cin >> C[i] >> S[i] >> F[i];
    }

    for(int i = 0; i < N; i++) {
        int currentTime = 0;
        for(int j = i; j < N-1; j++) {
            if(currentTime < S[j]) {
                currentTime = S[j];
            } else if(currentTime % F[j] != 0) {
                currentTime += F[j] - (currentTime % F[j]);
            }
            currentTime += C[j];
        }
        cout << currentTime << endl;
    }

    return 0;
}