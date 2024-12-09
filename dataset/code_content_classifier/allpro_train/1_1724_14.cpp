#include <bits/stdc++.h>
using namespace std;

int main(){
          int n,m;
          int i,j;
          while(1){
                    int sc;
                    int ans=0;
                    cin >> n >>m;
                    if(!n&&!m) break;
                    vector <int>sum(n);
                    for(i=0;i<m;i++){
                              for(j=0;j<n;j++){
                                        cin >> sc;
                                        sum[j]+=sc;
                              }
                    }
                    for(i=0;i<n;i++)ans = max(ans, sum[i]);
                    cout <<ans<<endl;
          }
}
