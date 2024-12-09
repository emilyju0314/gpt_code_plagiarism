#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> services;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        services.push_back({a, b});
    }

    bool possible = false;
    for(auto service : services) {
        if(service.first == 1) {
            for(auto nextService : services) {
                if(nextService.first == service.second && nextService.second == N) {
                    possible = true;
                    break;
                }
            }
        }
    }

    if(possible) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}