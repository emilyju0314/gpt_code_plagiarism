#include<iostream>
#include<vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> l(m);
    for(int i=0; i<m; i++) {
        cin >> l[i];
    }

    int sum = 0;
    for(int i=0; i<m; i++) {
        sum += l[i];
    }

    if(sum < n) {
        cout << -1 << endl;
        return 0;
    }

    int current = 1;
    for(int i=0; i<m; i++) {
        cout << current << " ";
        current += l[i];
    }

    return 0;
}