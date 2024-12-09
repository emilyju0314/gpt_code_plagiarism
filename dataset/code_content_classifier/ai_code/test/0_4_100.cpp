#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int minElement = *min_element(arr.begin(), arr.end());
        int maxMinElement = minElement;
        
        while (arr.size() > 1) {
            vector<int> remaining;
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] != minElement) {
                    remaining.push_back(arr[i] - minElement);
                }
            }
            arr = remaining;
            if(arr.size() > 0){
                minElement = *min_element(arr.begin(), arr.end());
                maxMinElement = max(maxMinElement, minElement);
            }
        }

        cout << maxMinElement << endl;
    }

    return 0;
}