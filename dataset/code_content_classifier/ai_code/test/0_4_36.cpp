#include <iostream>
#include <vector>

using namespace std;

bool isComposite(int num) {
    for(int i = 2; i < num; i++) {
        if(num % i == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int totalSum = 0;
        for(int i = 0; i < n; i++) {
            totalSum += arr[i];
        }

        if(isComposite(totalSum)) {
            cout << n << endl;
            for(int i = 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << endl;
        } else {
            vector<int> subset;
            for(int i = 0; i < n; i++) {
                int subsetSum = arr[i];
                for(int j = i+1; j < n; j++) {
                    subsetSum += arr[j];
                    if(isComposite(subsetSum)) {
                        subset.push_back(i+1);
                        subset.push_back(j+1);
                        break;
                    }
                }
                if(!subset.empty()) {
                    break;
                }
            }
            cout << subset.size() << endl;
            for(int i = 0; i < subset.size(); i++) {
                cout << subset[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}