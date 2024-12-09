#include <iostream>
#include <vector>

using namespace std;

bool isComposite(int num) {
    if(num < 4) {
        return false;
    }
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

        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
        }

        if(isComposite(sum)) {
            cout << n << endl;
            for(int i = 1; i <= n; i++) {
                cout << i << " ";
            }
            cout << endl;
        } else {
            vector<int> indices;
            for(int i = 0; i < n; i++) {
                for(int j = i+1; j < n; j++) {
                    int tempSum = arr[i] + arr[j];
                    if(isComposite(tempSum)) {
                        if(indices.empty() || (j - i + 1) > indices.size()) {
                            indices.clear();
                            for(int k = i; k <= j; k++) {
                                indices.push_back(k+1);
                            }
                        }
                    }
                }
            }
            cout << indices.size() << endl;
            for(int i = 0; i < indices.size(); i++) {
                cout << indices[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}