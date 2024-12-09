#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> impostors;
        vector<int> indices;
        
        for (int i = 1; i <= n; i += 3) {
            cout << "? " << i << " " << i + 1 << " " << i + 2 << endl;
            int r;
            cin >> r;
            if (r == 0) {
                impostors.push_back(i);
                impostors.push_back(i + 1);
                impostors.push_back(i + 2);
            } else {
                indices.push_back(i);
                indices.push_back(i + 1);
                indices.push_back(i + 2);
            }
        }
        
        if (impostors.size() < indices.size()) {
            for (int i = 1; i <= n; i++) {
                if (find(indices.begin(), indices.end(), i) == indices.end()) {
                    cout << "? " << indices[0] << " " << indices[1] << " " << i << endl;
                    int r;
                    cin >> r;
                    if (r == 0) {
                        impostors.push_back(i);
                    }
                }
            }
        } else {
            for (int i = 1; i <= n; i++) {
                if (find(impostors.begin(), impostors.end(), i) == impostors.end()) {
                    cout << "? " << impostors[0] << " " << impostors[1] << " " << i << endl;
                    int r;
                    cin >> r;
                    if (r == 0) {
                        indices.push_back(i);
                    }
                }
            }
        }
        
        cout << "! " << impostors.size() << " ";
        for (int i = 0; i < impostors.size(); i++) {
            cout << impostors[i] << " ";
        }
        cout << endl;
        cout.flush();
    }
    
    return 0;
}