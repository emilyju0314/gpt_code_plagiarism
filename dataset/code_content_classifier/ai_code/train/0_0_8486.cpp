#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> score(N);
    for(int i = 0; i < N; i++) {
        cin >> score[i];
    }
    
    int fingers = 1;
    for(int i = 1; i < N; i++) {
        if(score[i] == score[i-1]) {
            continue;
        } else {
            fingers = max(abs(score[i] - score[i-1]), fingers);
        }
    }
    
    cout << fingers << endl;
    
    return 0;
}