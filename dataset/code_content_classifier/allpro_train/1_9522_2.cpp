#include <bits/stdc++.h>
using namespace std;

int main() {
  string s[12]={"C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};
  string t[5]={"","7","M7","m","m7"};
  string r[11]={"","-9","9","+9","-11","11","+11","","-13","13","+13"};
  int d[5][4]={{0,4,7,-1},{0,4,7,10},{0,4,7,11},{0,3,7,-1},{0,3,7,10}};
  int T;
  cin >> T;
  while(T--) {
    int n;
    cin >> n;
    vector<int> a(12,0);
    for(int i=0; i<n; i++) {
      string e;
      cin >> e;
      for(int j=0; j<12; j++) {
        if(s[j]==e) {
          a[j]=1;
          break;
        }
      }
    }
    vector<string> ans;
    for(int i=0; i<12; i++) {
      for(int j=0; j<5; j++) {
        vector<int> b(12,0);
        for(int k=0; k<4; k++) {
          if(d[j][k]==-1) break;
          b[(i+d[j][k])%12]=1;
        }
        if(a==b) {
          ans.push_back(s[i]+t[j]);
          continue;
        }
        for(int k=1; k<11; k++) {
          if(k==7) continue;
          int x=b[(i+k)%12];
          b[(i+k)%12]=1;
          if(a==b) ans.push_back(s[i]+t[j]+"("+r[k]+")");
          b[(i+k)%12]=x;
        }
        b[(i+7)%12]=0;b[(i+6)%12]=1;
        if(a==b) ans.push_back(s[i]+t[j]+"(-5)");
        b[(i+6)%12]=0;b[(i+8)%12]=1;
        if(a==b) ans.push_back(s[i]+t[j]+"(+5)");
      }
    }
    if(ans.size()) {
      for(int i=0; i<ans.size(); i++) {
        if(i) cout << " ";
        cout << ans[i];
      }
      cout << endl;
    } else cout << "UNKNOWN" << endl;
  }
  return 0;
}