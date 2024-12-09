#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> p(N);
    for(int i=0; i<N; i++) {
        cin >> p[i];
    }

    vector<pair<int,int>> swaps(M);
    for(int i=0; i<M; i++) {
        cin >> swaps[i].first >> swaps[i].second;
    }

    int count = 0;
    vector<bool> fixed(N, false);
    for(int i=0; i<N; i++) {
        if(p[i] == i+1) {
            count++;
            fixed[i] = true;
        }
    }

    for(int i=0; i<M; i++) {
        int x = swaps[i].first - 1;
        int y = swaps[i].second - 1;

        if((!fixed[x] && !fixed[y]) || (fixed[x] && fixed[y])) {
            continue;
        }

        if(fixed[x]) {
            swap(x, y);
        }
        if(p[x] == x+1) {
            count++;
        }
        fixed[x] = true;
    }

    cout << count << endl;

    return 0;
}