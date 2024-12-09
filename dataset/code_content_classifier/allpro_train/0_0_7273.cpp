#include <iostream>
#include <vector>

using namespace std;

int findMatchingSize(int X, int Y, int E, vector<pair<int, int>>& edges) {
    vector<int> match(Y, -1);
    int matchingSize = 0;

    for (int i = 0; i < E; i++) {
        int x = edges[i].first;
        int y = edges[i].second;

        if (match[y] == -1) {
            match[y] = x;
            matchingSize++;
        } else {
            if (match[y] != x) {
                for (int j = 0; j < Y; j++) {
                    if (match[y] != -1 && match[y] != x) {
                        int prevX = match[y];
                        match[y] = x;
                        x = prevX;
                    }
                }
            }
        }
    }

    return matchingSize;
}

int main() {
    int X, Y, E;
    cin >> X >> Y >> E;

    vector<pair<int, int>> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    int largestMatchingSize = findMatchingSize(X, Y, E, edges);
    cout << largestMatchingSize << endl;

    return 0;
}