#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<vector<int>> arrays(N, vector<int>());
    vector<int> queries(Q);

    for(int i=0; i<M; i++) {
        int a, b, v;
        cin >> a >> b >> v;
        for(int j=a-1; j<=b-1; j++) {
            arrays[j].push_back(v);
        }
    }

    for(int i=0; i<Q; i++) {
        int x, y, j;
        cin >> x >> y >> j;
        vector<int> temp;
        for(int k=x-1; k<=y-1; k++) {
            for(int num : arrays[k]) {
                temp.push_back(num);
            }
        }
        sort(temp.begin(), temp.end());
        cout << temp[j-1] << endl;
    }

    return 0;
}