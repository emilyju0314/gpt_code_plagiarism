#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> chocolate(n);
    for(int i = 0; i < n; i++) {
        cin >> chocolate[i];
    }

    int total_nuts = 0;
    for(int i = 0; i < n; i++) {
        total_nuts += chocolate[i];
    }

    int ways = 0;
    int current_nuts = 0;
    for(int i = 0; i < n-1; i++) {
        current_nuts += chocolate[i];
        if(current_nuts * 2 == total_nuts) {
            ways++;
        }
    }

    cout << ways << endl;

    return 0;
}