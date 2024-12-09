#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    map<int, int> mp;
    for(int i=0; i<N+M; i++){
        int a;
        cin >> a;
        mp[a]++;
    }
    vector<int> And, Or;
    for(auto& p : mp){
        if(p.second == 2) And.push_back(p.first);
        Or.push_back(p.first);
    }
    cout << And.size() << " " << Or.size() << endl;
    for(int a : And) cout << a << endl;
    for(int a : Or) cout << a << endl;
}

