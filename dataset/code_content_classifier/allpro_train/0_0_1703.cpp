#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> jars(n);
    vector<int> target(n);
    for(int i=0; i<n; i++) {
        cin >> jars[i];
        target[jars[i]-1] = i+1;
    }

    vector<vector<int>> operations;
    int count = 0;

    for(int i=0; i<n; i++) {
        if(jars[i] != i+1) {
            count++;
            int j = i;
            while (j < n && target[jars[j]-1] != jars[j]) {
                j++;
            }

            vector<int> op;
            op.push_back(j-i);
            for(int k=i; k<j; k++) {
                op.push_back(k+1);
            }

            for(int k=j-1; k>=i; k--) {
                jars[target[jars[k]-1]-1] = jars[k];
            }

            for(int k=1; k<=j-i; k++) {
                jars[i+k-1] = target[jars[i+k-1]];
            }
            operations.push_back(op);
        }
    }

    cout << count << endl;
    for(const auto& op : operations) {
        cout << op[0] << endl;
        for(int i=1; i<=op[0]; i++) {
            cout << op[i] << " ";
        }
        cout << endl;
        for(int i=1; i<=op[0]; i++) {
            cout << target[jars[op[i]-1]] << " ";
        }
        cout << endl;
    }

    return 0;
}