#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n+1);
    vector<int> apples(n+1, 0);

    for(int i = 2; i <= n; i++) {
        int pi;
        cin >> pi;
        p[i] = pi;
    }

    apples[1] = 1;

    for(int i = 2; i <= n; i++) {
        int parent = p[i];
        apples[i] = min(1, apples[parent] - 1);
        apples[parent] = max(apples[parent], 1);
    }

    int collectedApples = 0;
    for(int i = 1; i <= n; i++) {
        if(apples[i] == 0) {
            collectedApples++;
        }
    }

    cout << collectedApples << endl;

    return 0;
}