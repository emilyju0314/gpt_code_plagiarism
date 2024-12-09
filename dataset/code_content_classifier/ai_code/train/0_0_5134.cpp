#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> files(m);

    for (int i = 0; i < m; i++) {
        int ni;
        cin >> ni;

        vector<int> file(ni);
        for (int j = 0; j < ni; j++) {
            cin >> file[j];
        }

        files[i] = file;
    }

    int unused = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < files[i].size(); j++) {
            if (files[i][j] != unused) {
                cout << files[i][j] << " " << unused << endl;
            }
            unused++;
        }
    }

    return 0;
}