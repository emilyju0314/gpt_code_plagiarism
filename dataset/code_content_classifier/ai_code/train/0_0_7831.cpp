#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> songs(n);
    for (int i = 0; i < n; i++) {
        cin >> songs[i];
    }

    int total_time = 0;
    for (int i = 0; i < n; i++) {
        total_time += songs[i];
    }

    if ((n-1)*10 + total_time <= d) {
        int jokes = ((n-1)*10 + total_time)/5;
        cout << jokes << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}