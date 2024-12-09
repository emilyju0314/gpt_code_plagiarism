#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> personalTokens(n+1, 1); // every member receives one personal token
    vector<vector<int>> friendshipTokens(n+1, vector<int>(n+1, 0));

    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;

        friendshipTokens[a][b] += 2;
        friendshipTokens[b][a]++;
    }

    vector<int> friendsKeepingTokens;

    for(int i = 1; i <= n; i++) {
        bool keepPersonalToken = true;
        for(int j = 1; j <= n; j++) {
            if(i != j && friendshipTokens[i][j] == personalTokens[j]) {
                keepPersonalToken = false;
                break;
            }
        }
        if(keepPersonalToken) {
            friendsKeepingTokens.push_back(i);
        }
    }

    cout << friendsKeepingTokens.size() << endl;
    for(int friend : friendsKeepingTokens) {
        cout << friend << " ";
    }
    cout << endl;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i < j) {
                cout << i << " " << j << " " << friendshipTokens[i][j] << endl;
            }
        }
    }

    return 0;
}