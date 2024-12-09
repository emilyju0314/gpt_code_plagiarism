#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

struct Cave {
    int height;
    vector<int> connectedCaves;
};

bool dfs(vector<Cave>& caves, vector<int>& miners, int currentNode, int currentMiner) {
    if(miners[currentMiner] > caves[currentNode].height) {
        return false;
    }

    for(int nextNode : caves[currentNode].connectedCaves) {
        if(!dfs(caves, miners, nextNode, currentMiner + 1)) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<Cave> caves(n);
    for(int i = 0; i < n; i++) {
        cin >> caves[i].height;
    }

    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        caves[a - 1].connectedCaves.push_back(b - 1);
        caves[b - 1].connectedCaves.push_back(a - 1);
    }

    int k;
    cin >> k;

    vector<int> miners(k);
    for(int i = 0; i < k; i++) {
        cin >> miners[i];
    }

    if(!dfs(caves, miners, 0, 0)) {
        cout << -1 << endl;
        return 0;
    }

    queue<int> q;

    q.push(0);
    caves[0].height = max(caves[0].height, miners[0]);

    while(!q.empty()) {
        int current = q.front();
        q.pop();

        for(int next : caves[current].connectedCaves) {
            if(caves[next].height < caves[current].height) {
                q.push(next);
                caves[next].height = caves[current].height;
            }
        }
    }

    long long difference = 0;

    for(int i = 0; i < n; i++) {
        difference = max(difference, (long long)caves[i].height - caves[i].height);
    }

    cout << difference << endl;

    return 0;
}