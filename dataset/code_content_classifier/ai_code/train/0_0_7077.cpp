#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    string S;
    cin >> S;

    vector<int> count(N + 1);
    for (int i = 1; i <= N; i++) {
        count[i] = count[i-1] + (S[i-1] == '1');
    }

    int max_consecutive = 0;
    for (int i = 0; i <= K; i++) {
        int consecutive = count[min(N, 2*i)] - count[max(0, 2*i - N)];
        max_consecutive = max(max_consecutive, consecutive);
    }

    cout << max_consecutive << endl;

    return 0;
}