#include <iostream>
#include <vector>

using namespace std;

int countRemotePlanets(int N, vector<vector<int>> tunnels) {
    vector<int> degrees(N+1, 0);
    for(auto tunnel : tunnels) {
        degrees[tunnel[0]]++;
        degrees[tunnel[1]]++;
    }

    int count = 0;
    for(int i=1; i<=N; i++) {
        if(degrees[i] == 1) {
            count++;
        }
    }

    return count;
}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> tunnels;

    for(int i=0; i<N-1; i++) {
        int u, v;
        cin >> u >> v;
        tunnels.push_back({u, v});
    }

    int result = countRemotePlanets(N, tunnels);
    cout << result << endl;

    return 0;
}