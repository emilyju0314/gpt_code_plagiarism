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

        vector<int> selected_items;
        long long total_weight = 0;
        bool found = false;

        for(int i = 0; i < n; i++) {
            if(weights[i] >= (W+1)/2 && weights[i] <= W) {
                total_weight = weights[i];
                selected_items.push_back(i+1);
                found = true;
                break;
            }
        }

        if(!found) {
            for(int i = 0; i < n; i++) {
                if(total_weight + weights[i] >= (W+1)/2 && total_weight + weights[i] <= W) {
                    total_weight += weights[i];
                    selected_items.push_back(i+1);
                }

                if(total_weight >= (W+1)/2) {
                    found = true;
                    break;
                }
            }
        }

        if(found) {
            cout << selected_items.size() << endl;
            for(int item : selected_items) {
                cout << item << " ";
            }
            cout << endl;
        } else {
            cout << "-1" << endl;
        }
    }

    return 0;
}