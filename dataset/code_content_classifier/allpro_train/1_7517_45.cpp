#include <iostream>
using namespace std;

#define REP(i,n,m) for(int i=n;i<m;i++)
#define rep(i,n) REP(i,0,n)

int w,h;
int t[31][31],s[31][31];
int di[] = {-1,0,1,0};
int dj[] = {0,1,0,-1};

void chDir(void){
	rep(i,h)rep(j,w)if(t[i][j]>=0)for(int k=1;k>=-2;k--){
		int nd = (t[i][j] + 4 + k) % 4;
		int ni = i + di[nd];
		int nj = j + dj[nd];

		if(t[ni][nj] == -1 || t[ni][nj] == -2){
			t[i][j] = nd;
			break;
		}
	}
}

void printMapT(void){
	rep(i,h){
		rep(j,w){
			if(t[i][j] == 0) cout<<"N";
			if(t[i][j] == 1) cout<<"E";
			if(t[i][j] == 2) cout<<"S";
			if(t[i][j] == 3) cout<<"W";
			if(t[i][j] == -1) cout<<"X";
			if(t[i][j] == -2) cout<<".";
			if(t[i][j] == -3) cout<<"#";
		}
		cout<<endl;
	}
	cout<<endl;
}

void printMapS(void){
	rep(i,h){
		rep(j,w){
			if(s[i][j] == 0) cout<<"N";
			if(s[i][j] == 1) cout<<"E";
			if(s[i][j] == 2) cout<<"S";
			if(s[i][j] == 3) cout<<"W";
			if(s[i][j] == -1) cout<<"X";
			if(s[i][j] == -2) cout<<".";
			if(s[i][j] == -3) cout<<"#";
		}
		cout<<endl;
	}
	cout<<endl;
}

int move(void){
	int res = 0;

	rep(i,h)rep(j,w)s[i][j] = t[i][j];

	rep(i,h)rep(j,w)if(t[i][j] == -1 || t[i][j] == -2)for(int k=1;k>=-2;k--){
		int nd = (k + 4) % 4;
		int ni = i + di[nd];
		int nj = j + dj[nd];

		if(ni>=0 && ni<h && nj>=0 && nj<w && t[ni][nj]>=0 && t[ni][nj]==(nd+2)%4){
			if(t[i][j] == -1) res++;
			else s[i][j] = t[ni][nj];
			s[ni][nj] = -2;
			break;
		}
	}

	rep(i,h)rep(j,w)t[i][j] = s[i][j];

	return res;
}

int main(void){
	while(cin>>w>>h && (w || h)){
		int rem = 0;
		char ch;

		rep(i,h){
			rep(j,w){
				cin>>ch;
				if(ch == 'X') t[i][j] = -1;
				else if(ch == '.') t[i][j] = -2;
				else if(ch == '#') t[i][j] = -3;
				else if(ch == 'N'){t[i][j] = 0; rem++;}
				else if(ch == 'E'){t[i][j] = 1; rem++;}
				else if(ch == 'S'){t[i][j] = 2; rem++;}
				else if(ch == 'W'){t[i][j] = 3; rem++;}
			}
		}

		int ans;
		for(ans=0;ans<180 && rem!=0;ans++){
			chDir();
			rem -= move();
		}
		if(ans == 180) cout<<"NA\n";
		else cout<<ans<<endl;
	}

	return 0;
}