#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    unordered_map<int, int> props;
    vector<vector<int>> same_value(N+1);

    for (int i = 1; i <= N; i++) {
        props[i] = i;
        same_value[i].push_back(i);
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        for (int j = 1; j <= N; j++) {
            if (props[j] == a) {
                props[j] = b;
                same_value[b].push_back(j);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int prop : same_value[i]) {
            cout << prop << " ";
        }
        cout << endl;
    }

    return 0;
}