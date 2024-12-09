#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> table(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> table[i][j];
        }
    }

    vector<pair<char, pair<int, int>>> queries(k);
    for(int i=0; i<k; i++) {
        char si;
        int xi, yi;
        cin >> si >> xi >> yi;
        queries[i] = make_pair(si, make_pair(xi, yi));
    }

    for(auto query : queries) {
        char si = query.first;
        int xi = query.second.first;
        int yi = query.second.second;

        if(si == 'c') {
            xi--; yi--;
            for(int i=0; i<n; i++) {
                swap(table[i][xi], table[i][yi]);
            }
        } else if(si == 'r') {
            xi--; yi--;
            for(int j=0; j<m; j++) {
                swap(table[xi][j], table[yi][j]);
            }
        } else if(si == 'g') {
            xi--; yi--;
            cout << table[xi][yi] << endl;
        }
    }

    return 0;
}