#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> a(n+1);
    vector<long long> num(n,0);
    for(int i=0;i<n;i++) {
        cin >> a[i].first;
        a[i].second=i;
    }
    a[n]={0,-1};
    sort(a.rbegin(),a.rend());
    priority_queue<int,vector<int>,greater<int>> que;
    for(int i=0;i<n+1;i++){
        if(i>0 && a[i].first<a[i-1].first){
            num[que.top()] += (a[i-1].first-a[i].first) * que.size();
        }
        que.push(a[i].second);
    }
    for(int i=0;i<n;i++) cout << num[i] << endl;
}