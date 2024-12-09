#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> frogs(n);
    for (int i = 0; i < n; i++) {
        cin >> frogs[i].first >> frogs[i].second;
    }

    vector<pair<int, int>> mosquitoes(m);
    for (int i = 0; i < m; i++) {
        cin >> mosquitoes[i].first >> mosquitoes[i].second;
    }

    sort(frogs.begin(), frogs.end());

    vector<int> eaten(n, 0);
    vector<int> tongueLength(n);
    
    for (int i = 0; i < m; i++) {
        int mosquitoPos = mosquitoes[i].first;
        int mosquitoSize = mosquitoes[i].second;
        
        for (int j = 0; j < n; j++) {
            if (mosquitoPos >= frogs[j].first && mosquitoPos <= frogs[j].first + frogs[j].second) {
                eaten[j]++;
                tongueLength[j] += mosquitoSize;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << eaten[i] << " " << frogs[i].second + tongueLength[i] << endl;
    }

    return 0;
}