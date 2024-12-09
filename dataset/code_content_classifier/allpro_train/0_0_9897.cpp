#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Victim {
    string name;
    int suspicion;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Victim> victims(n);
    for (int i = 0; i < n; i++) {
        cin >> victims[i].name;
        victims[i].suspicion = 0;
    }

    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int idx, x;
            cin >> idx >> x;
            victims[idx - 1].suspicion = x;
        } else if (type == 2) {
            string q;
            cin >> q;
            
            int max_suspicion = -1;
            for (int j = 0; j < n; j++) {
                size_t found = q.find(victims[j].name);
                if (found != string::npos && victims[j].suspicion > max_suspicion) {
                    max_suspicion = victims[j].suspicion;
                }
            }
            cout << max_suspicion << endl;
        }
    }

    return 0;
}