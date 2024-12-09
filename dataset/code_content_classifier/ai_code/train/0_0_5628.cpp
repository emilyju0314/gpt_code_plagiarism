#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> tweets(N);
    for (int i = 0; i < N; i++) {
        cin >> tweets[i];
    }
    
    vector<int> display(N, 0);
    
    for (int i = 0; i < N; i++) {
        if (tweets[i] == 0) {
            display[i] = 1;
        } else {
            int count = 0;
            int j = i;
            while (tweets[j] != 0) {
                j = tweets[j] - 1;
                count++;
                if (count > K) break;
            }
            if (count <= K) {
                display[i] = 1;
            }
        }
    }
    
    int result = 0;
    for (int i = 0; i < N; i++) {
        result += display[i];
    }
    
    cout << result << endl;
    
    return 0;
}