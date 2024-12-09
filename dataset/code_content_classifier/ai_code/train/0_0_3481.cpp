#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> redBerries(n);
    vector<int> blueBerries(n);

    for(int i = 0; i < n; i++) {
        cin >> redBerries[i] >> blueBerries[i];
    }

    int totalBaskets = 0;

    for(int i = 0; i < n; i++) {
        int basketsFromShrub = 0;

        basketsFromShrub += redBerries[i] / k;
        basketsFromShrub += blueBerries[i] / k;

        totalBaskets = max(totalBaskets, basketsFromShrub);
    }

    cout << totalBaskets << endl;

    return 0;
}