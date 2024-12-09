#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> types(n);
    for (int i = 0; i < n; i++) {
        cin >> types[i];
    }
    
    vector<int> tracks(n);
    for (int i = 0; i < n; i++) {
        cin >> tracks[i];
    }
    
    int hotel = -1;
    for (int i = 0; i < n; i++) {
        if (types[i] == 1) {
            hotel = i;
        }
    }
    
    int k = 1;
    vector<int> path;
    path.push_back(hotel + 1);
    int current = tracks[hotel];
    while (current != 0) {
        path.push_back(current);
        k++;
        current = tracks[current - 1];
    }
    
    cout << k << endl;
    for (int i = 0; i < k; i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    
    return 0;
}