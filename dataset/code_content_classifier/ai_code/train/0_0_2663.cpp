#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    int N = S.size();
    int count[N] = {0};

    int current = 0;
    for(int i=0; i<N; i++){
        if(S[i] == 'R'){
            if(current % 2 == 0){
                count[current]++;
            } else {
                count[current+1]++;
            }

            current = 0;
        } else {
            current++;
        }
    }

    current = 0;
    for(int i=N-1; i>=0; i--){
        if(S[i] == 'L'){
            if(current % 2 == 0){
                count[current]++;
            } else {
                count[current-1]++;
            }

            current = 0;
        } else {
            current++;
        }
    }

    for(int i=0; i<N; i++){
        cout << count[i] << " ";
    }

    return 0;
}