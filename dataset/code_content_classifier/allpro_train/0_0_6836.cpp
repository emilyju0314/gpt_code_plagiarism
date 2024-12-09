#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int A, B, K;
    cin >> A >> B >> K;

    vector<vector<int>> a(A, vector<int>(B));
    vector<vector<int>> b(B, vector<int>(A));

    for(int i = 0; i < A; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < B; j++) {
            a[i][j] = s[j] - '0';
        }
    }

    for(int i = 0; i < B; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < A; j++) {
            b[i][j] = s[j] - '0';
        }
    }

    int count = 0;
    vector<bool> visited(A, false);
    for(int i = 0; i < min(A, B); i++) {
        vector<bool> used(B, false);
        bool found = false;
        for(int j = 0; j < A; j++) {
            if(visited[j]) continue;
            for(int k = 0; k < B; k++) {
                if(!used[k] && a[j][k] == 0 && b[k][j] == 0) {
                    count++;
                    used[k] = true;
                    visited[j] = true;
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
    }

    cout << count << endl;

    return 0;
}