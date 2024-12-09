#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i];
        }

        string s;
        cin >> s;

        vector<int> liked, disliked;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                liked.push_back(p[i]);
            } else {
                disliked.push_back(p[i]);
            }
        }

        sort(liked.begin(), liked.end());
        sort(disliked.begin(), disliked.end());

        vector<int> q(n);
        int liked_ptr = 0, disliked_ptr = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                q[i] = liked[liked_ptr++];
            } else {
                q[i] = disliked[disliked_ptr++];
            }
        }

        for(int i = 0; i < n; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }

    return 0;
}