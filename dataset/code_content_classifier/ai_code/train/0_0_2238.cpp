#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, K, L;
    cin >> N >> K >> L;

    vector<set<int>> roads(N + 1), railways(N + 1);

    for (int i = 0; i < K; i++) {
        int p, q;
        cin >> p >> q;
        roads[p].insert(q);
        roads[q].insert(p);
    }

    for (int i = 0; i < L; i++) {
        int r, s;
        cin >> r >> s;
        railways[r].insert(s);
        railways[s].insert(r);
    }

    vector<int> total_connections(N + 1);

    for (int i = 1; i <= N; i++) {
        set<int> common_connections;
        
        for (int city : roads[i]) {
            if (railways[i].count(city) > 0) {
                common_connections.insert(city);
            }
        }

        total_connections[i] = common_connections.size() + 1;
    }

    for (int i = 1; i <= N; i++) {
        cout << total_connections[i] << " ";
    }

    cout << endl;

    return 0;
}