#include <iostream>
using namespace std;

int main() {
	int s,i,j,x,y,c[15][15],d[17][15];
	while(cin >> x >> y) {
		if (x+y==0) break;
		for (i=0;i<y;i++) for (j=0;j<x;j++) cin >> c[i][j];
		for (i=0;i<y+2;i++) for (j=0;j<x;j++) d[i][j]=(i==0);
		for (i=0;i<y-1;i++) for (j=0;j<x;j++) {
			s=d[i][j];
			if (c[i][j]==0) { 
				if (j>0) if (c[i+1][j-1]==0) d[i+1][j-1]+=s;
				if (j<x-1) if (c[i+1][j+1]==0) d[i+1][j+1]+=s;
				if (c[i+1][j]!=1) d[i+1][j]+=s;
			}
			if (c[i][j]==2 && c[i+2][j]!=1) d[i+2][j]+=s;
		}
		s=0;
		for (i=y-1;i<=y;i++) for (j=0;j<x;j++) s+=d[i][j];
		if (y==1) { s=0; for (i=0;i<x;i++) s+=(c[0][i]==0);}
		cout << s << endl; 
	 }
	return 0;
}