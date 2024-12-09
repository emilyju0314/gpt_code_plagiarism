#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> s(N);
    for(int i = 0; i < N; i++) {
        cin >> s[i];
    }

    long long max_score = 0;
    
    for(int A = 1; A <= N-2; A++) {
        for(int B = 1; B <= N-2; B++) {
            int x = 0;
            int score = 0;
            vector<bool> visited(N, false);

            while(x != N-1) {
                if(x + A < N && !visited[x + A]) {
                    visited[x + A] = true;
                    score += s[x + A];
                    x = x + A;
                } else if(x - B >= 0 && !visited[x - B]) {
                    visited[x - B] = true;
                    score += s[x - B];
                    x = x - B;
                } else {
                    score -= pow(10, 100);
                    break;
                }
            }

            max_score = max(max_score, (long long)score);
        }
    }

    cout << max_score << endl;

    return 0;
}