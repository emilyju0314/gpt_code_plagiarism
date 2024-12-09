#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 500000;

vector<int> children[MAXN+1];
bool waterFilled[MAXN+1];

void fillVertex(int v) {
    waterFilled[v] = true;
    for(int child : children[v]) {
        fillVertex(child);
    }
}

void emptyVertex(int v) {
    waterFilled[v] = false;
    if(v != 1) {
        emptyVertex(v-1);
    }
}

bool isVertexFilled(int v) {
    return waterFilled[v];
}

int main() {
    int n;
    cin >> n;

    for(int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        children[parent].push_back(i);
    }

    int q;
    cin >> q;

    while(q--) {
        int c, v;
        cin >> c >> v;

        if(c == 1) {
            fillVertex(v);
        } else if(c == 2) {
            emptyVertex(v);
        } else if(c == 3) {
            cout << isVertexFilled(v) << endl;
        }
    }

    return 0;
}