#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int max_piles = 0;
    int current_pile = 0;

    for(int i = 0; i < n; i++) {
        current_pile = max(current_pile, x[i]);
        if(current_pile == i) {
            max_piles++;
            current_pile = 0;
        }
    }

    if(current_pile > 0) {
        max_piles++;
    }

    cout << max_piles << endl;

    return 0;
}