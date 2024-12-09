#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;

ll bit[300100];

ll n,p[300100],l[300100];

void init(int n){
  for(int i=1;i<=n;i++)bit[i] = 0;
}

ll sum(int i){
  ll res = 0;
  while(i>0){
    res += bit[i];
    i -= i&-i;
  }
  return res;
}

void add(int i,ll val){
  while(i<=n){
    bit[i] += val;
    i += i&-i;
  }
}

int main(){
  cin >> n;
  vector<ll> s(n+1), ss(n+1);

  ss[0] = s[0] = 0;
  for(int i=0;i<n;i++){
    cin >> p[i];
    ss[i+1] = s[i+1] = s[i] + p[i];
  }

  for(int i=0;i<n;i++)cin >> l[i];

  sort(ss.begin(),ss.end());

  for(int i=0;i<n;i++){
    if(ss[i+1]-ss[i]<l[i]){
      cout << -1 << endl;
      return 0;
    }
  }

  n++;  
  ss.erase(unique(ss.begin(),ss.end()), ss.end());
  for(int i=0;i<n;i++){
    s[i] = lower_bound(ss.begin(),ss.end(),s[i]) - ss.begin();
  }

  init(n);
  ll res = 0;

  for(int i=n-1;i>=0;i--){
    res += sum(s[i]+1);
    add(s[i]+1,1);
  }
  
  cout << res << endl;
}