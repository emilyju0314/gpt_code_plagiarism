#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;

    vector<vector<char> > a(n,vector<char>(m));

    vector<vector<char> > b(n,vector<char>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>b[i][j];
        }
    }

    int count=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] != b[i][j]) count++;
        }
    }

    cout<<count<<endl;

    return 0;
}
