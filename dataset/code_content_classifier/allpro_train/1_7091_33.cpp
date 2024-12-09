#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, p;
    while(cin >> n >> m >> p, n != 0){
        vector<int> v;
        int sum = 0;
        for(int i=0;i<n;++i){
            int x;
            cin >> x;
            v.push_back(x);
            sum += x;
        }
        cout << (v[m-1] ? sum * (100-p) / v[m-1] : 0) << endl;
    }

    return 0;
}
