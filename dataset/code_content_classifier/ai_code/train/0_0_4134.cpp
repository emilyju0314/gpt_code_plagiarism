#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int MAXN = 605;
const double INF = 1e18;

int N, M;
vector<pair<int, int>> passages;
vector<vector<int>> adjList(MAXN);
double dp[MAXN];

double solve(int room) {
    if(room == N) return 0;

    if(dp[room] != -1) return dp[room];

    double total = 0;
    for(int nextRoom : adjList[room]){
        total += 1 + solve(nextRoom);
    }

    return dp[room] = total / adjList[room].size();
}

int main() {
    cin >> N >> M;
    passages.resize(M);
    for(int i=0;i<M;i++){
        int s, t;
        cin >> s >> t;
        passages[i] = {s, t};
        adjList[s].push_back(t);
    }

    fill(dp, dp+MAXN, -1);
    cout << fixed << setprecision(10) << solve(1) << endl;

    return 0;
}