#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int MAXN = 500005;

vector<int> parent(MAXN, -1);
vector<int> height(MAXN, 0);
vector<int> subtreeSize(MAXN, 1);

double expectedPenalty(int v) {
    double ans = 0.0;
    int totalVertices = subtreeSize[v];
    
    for (int u = v+1; u < MAXN; u++) {
        if (parent[u] == v) {
            ans += (1.0 - pow(0.5, height[u])) * (1 + expectedPenalty(u)) * subtreeSize[u] / totalVertices;
        }
    }
    
    return ans;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        int type, v;
        cin >> type >> v;

        if (type == 1) {
            parent[v] = 1;
            height[v] = height[1] + 1;
            for (int u = v; u != -1; u = parent[u]) {
                subtreeSize[u]++;
            }
        } else {
            cout << fixed << setprecision(10) << expectedPenalty(v) << endl;
        }
    }

    return 0;
}