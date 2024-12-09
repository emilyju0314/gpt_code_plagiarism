#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> P(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i];
    }

    int count = 0;
    for(int i = 0; i <= N - K; i++) {
        vector<int> sortedP = P;
        sort(sortedP.begin() + i, sortedP.begin() + i + K);
        
        bool isValid = true;
        for(int j = 0; j < N-1; j++) {
            if(sortedP[j] > sortedP[j+1]) {
                isValid = false;
                break;
            }
        }
        
        if(isValid) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}