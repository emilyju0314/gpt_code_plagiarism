#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
#include <set>
#include <map>
#include <queue>
#include <limits.h>
#include <cmath>

using namespace std;

#define rip(i,n,s) for (int i=(s);i<(int)(n);i++)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int,int> P;

int main(){
    string s;
    cin >> s;
    map<char,int> ma;
    int n=s.size();
    rip(i,n,0){
        if(ma.count(s[i])){
            ma[s[i]]++;
        }
        else{
            ma[s[i]]=1;
        }
    }
    if(ma.size()==1){
        cout << n << endl;
        return 0;
    }
    priority_queue<P,vector<P>,greater<P> > q;
    for (auto i:ma){
        q.push(make_pair(i.second,0));
    }
    P x,y;
    while(q.size()>1){
        x=q.top();
        q.pop();
        y=q.top();
        q.pop();
        q.push(make_pair(x.first+y.first,x.first+y.first+x.second+y.second));
    }
    cout << q.top().second << endl;
}
