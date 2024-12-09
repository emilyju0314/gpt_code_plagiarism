#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int N, Q;
    cin >> N;

    vector<int> magicPower(N);
    for(int i = 0; i < N; i++) {
        cin >> magicPower[i];
    }

    vector<vector<int>> adjList(N);
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a-1].push_back(b-1);
        adjList[b-1].push_back(a-1);
    }

    cin >> Q;

    unordered_map<int, int> powerChanges;
    for(int i = 0; i < Q; i++) {
        int type, classroom, change;
        cin >> type >> classroom >> change;
        
        if(type == 0) {
            int sum = 0;
            vector<bool> visited(N, false);
            vector<int> queue;
            queue.push_back(classroom-1);

            while(!queue.empty()) {
                int curr = queue.back();
                queue.pop_back();

                if(!visited[curr]) {
                    visited[curr] = true;
                    sum += magicPower[curr];
                    for(int neighbor : adjList[curr]) {
                        queue.push_back(neighbor);
                    }
                }
            }

            cout << sum + powerChanges[classroom] << endl;
        } else if(type == 1) {
            powerChanges[classroom] += change;
        }
    }

    return 0;
}