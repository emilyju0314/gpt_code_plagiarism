#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int n, m;
        cin >> n >> m;

        vector<int> p(n), q(n);
        vector<int> diff(n);

        for(int j=0; j<n; j++){
            p[j] = j+1;
            q[j] = j+1;
        }

        map<int, set<int>> pairs;
        
        for(int j=0; j<m; j++){
            int l, r;
            cin >> l >> r;
            pairs[l].insert(r);
            pairs[r].insert(l);
        }

        for(auto& pair : pairs){
            int l = pair.first;
            for(auto r : pair.second){
                if(diff[l-1] == 0 && diff[r-1] == 0){
                    diff[l-1] = 1;
                    diff[r-1] = -1;
                }
            }
        }

        int count = count(diff.begin(), diff.end(), 0);
        int cur = 2;

        for(int j=0; j<n; j++){
            if(diff[j] == 0){
                while(pairs[cur].count(cur) != 0){
                    cur++;
                }
                diff[j] = 1;
                diff[cur - 1] = -1;
                cur++;
            }
        }

        for(int j=0; j<n; j++){
            if(diff[j] == 1){
                cout << p[j] << " ";
            }
        }
        cout << endl;

        for(int j=0; j<n; j++){
            if(diff[j] == -1){
                cout << q[j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}