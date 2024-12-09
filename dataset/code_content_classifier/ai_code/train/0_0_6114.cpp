#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> lengths(n);
    for(int i = 0; i < n; i++) {
        cin >> lengths[i];
    }

    int alive = 1;
    int max_kill = 0;

    for(int i = 0; i < n; i++) {
        if(i > max_kill) {
            break;
        }
        max_kill = max(max_kill, i + lengths[i]);
        alive++;
    }

    cout << alive << endl;

    return 0;
}