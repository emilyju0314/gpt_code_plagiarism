#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<int> cities(n);
    for(int i = 0; i < n; i++) {
        cin >> cities[i];
    }

    int remaining = n * m;
    int teams = 0;

    for(int i = 0; i < n; i++) {
        if(i + k > n) {
            break;
        }
        int count = 1;
        while(i + count * k < n && cities[i] == cities[i + count * k]) {
            count++;
        }
        teams += count;

        remaining -= count * k;
        i += (count - 1);
    }

    cout << remaining << endl;

    return 0;
}