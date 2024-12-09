#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        long long W;
        cin >> n >> W;

        vector<int> weights(n);
        for(int i = 0; i < n; i++) {
            cin >> weights[i];
        }

        long long totalWeight = 0;
        int count = 0;
        vector<int> selectedItems;

        for(int i = 0; i < n; i++) {
            if(weights[i] >= (W+1)/2 && weights[i] <= W) {
                count = 1;
                selectedItems.push_back(i+1);
                break;
            }
            if(totalWeight + weights[i] <= W) {
                totalWeight += weights[i];
                count++;
                selectedItems.push_back(i+1);
            }
            if(totalWeight >= (W+1)/2) {
                break;
            }
        }

        if(totalWeight < (W+1)/2 || totalWeight > W) {
            cout << "-1\n";
        } else {
            cout << count << endl;
            for(int item : selectedItems) {
                cout << item << " ";
            }
            cout << endl;
        }
    }

    return 0;
}