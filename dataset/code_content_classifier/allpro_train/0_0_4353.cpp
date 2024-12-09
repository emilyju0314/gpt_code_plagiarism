#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        long long k;
        cin >> k;

        if(k % 2 == 1) {
            cout << -1 << endl;
        } else {
            vector<int> stages;
            k /= 2;
            while(k > 0) {
                stages.push_back(1); // Add a checkpoint
                k--;
                stages.push_back(0); // Add a stage without a checkpoint
            }

            // Print the result
            cout << stages.size() << endl;
            for(int i = 0; i < stages.size(); i++) {
                cout << stages[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}