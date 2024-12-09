#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> R(N), A(N), T(N), W(N);
    
    for(int i=0; i<N; i++){
        cin >> R[i] >> A[i] >> T[i] >> W[i];
    }

    int maxAttack = 0;

    for(int i=0; i<N; i++){
        int attack = A[i];
        int timeLeft = T[i];
        for(int j=i+1; j<N; j++){
            if(timeLeft > R[j]){
                attack += A[j];
                timeLeft = T[j];
            } else {
                attack += W[j];
            }
        }
        maxAttack = max(maxAttack, attack);
    }

    cout << maxAttack << endl;

    return 0;
}