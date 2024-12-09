#include <bits/stdc++.h>
using namespace std;

bool check(int x,int y, int z) {
  if(x<0 || x>=5) return false;
  if(y<0 || y>=5) return false;
  if(z<0 || z>=5) return false;
  return true;
}

int main() {
  int n,t=1;
  while(cin >> n && n) {
    int a[5][5][5];
    for(int i=0; i<5; i++) {
      for(int j=0; j<5; j++) {
	string s;
	cin >> s;
	for(int k=0; k<5; k++) {
	  if(s[k]=='1') a[i][j][k]=1;
	  else a[i][j][k]=0;
	}
      }
    }
    int m1,m2;
    set<int> s1,s2;
    cin >> m1;
    while(m1--) {
      int x;
      cin >> x;
      s1.insert(x);
    }
    cin >> m2;
    while(m2--) {
      int x;
      cin >> x;
      s2.insert(x);
    }
    while(n--) {
      int b[5][5][5];
      for(int i=0; i<5; i++) {
	for(int j=0; j<5; j++) {
	  for(int k=0; k<5; k++) b[i][j][k]=a[i][j][k];
	}
      }
      for(int i=0; i<5; i++) {
	for(int j=0; j<5; j++) {
	  for(int k=0; k<5; k++) {
	    int cnt=0;
	    for(int dx=-1; dx<=1; dx++) {
	      for(int dy=-1; dy<=1; dy++) {
		for(int dz=-1; dz<=1; dz++) {
		  int x=i+dx,y=j+dy,z=k+dz;
		  if(x==i && y==j && z==k) continue;
		  if(check(x,y,z)) cnt+=b[x][y][z];
		}
	      }
	    }
	    if(b[i][j][k]) {
	      if(!s2.count(cnt)) a[i][j][k]=0;
	    } else {
	      if(s1.count(cnt)) a[i][j][k]=1;
	    }
	  }
	}
      }
    }
    if(t>1) cout << endl;
    cout << "Case " << t++ << ":" << endl;
    for(int i=0; i<5; i++) {
      if(i) cout << endl;
      for(int j=0; j<5; j++) {
	for(int k=0; k<5; k++) cout << a[i][j][k];
	cout << endl;
      }
    }
  }
  return 0;
}