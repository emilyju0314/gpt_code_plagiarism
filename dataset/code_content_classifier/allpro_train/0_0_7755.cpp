#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int coins;
        cin >> coins;

        int count = 0;
        for (int j = 0; j < n; j++) {
            if (prices[j] <= coins) {
                count++;
            }
        }
        
        cout << count << endl;
    }

    return 0;
}