#include <bits/stdc++.h>
using namespace std;
# define rep(i,a,b) for(int i=(a); i<=(b); ++i)
# define drep(i,a,b) for(int i=(a); i>=(b); --i)
typedef long long int_;
inline int readint(){
	int a = 0; char c = getchar(), f = 1;
	for(; c<'0'||c>'9'; c=getchar())
		if(c == '-') f = -f;
	for(; '0'<=c&&c<='9'; c=getchar())
		a = (a<<3)+(a<<1)+(c^48);
	return a*f;
}

const int MaxN = 100005;
const int SqrtN = 500;

struct Node{
	int cnt, val;
	bool operator < (const Node &t) const {
		return cnt > t.cnt;
	}
};
Node num[MaxN];
int maze[SqrtN][SqrtN];

int main(){
	for(int T=readint(); T; --T){
		int m = readint(), k = readint();
		rep(i,1,k){
			num[i].cnt = readint();
			num[i].val = i;
		}
		sort(num+1,num+k+1); int n = 1;
		while(n*n-(n>>1)*(n>>1) < m) ++ n;
		while((n>>1)*((n+1)>>1) // red
			+(n*n+1)/2 // black
			-(n>>1)*(n>>1) < num[1].cnt)
				++ n; // increase
		/* step one: fuck one num */ ;
		for(int i=2; i<=n; i+=2)
		for(int j=1; j<=n&&num[1].cnt; j+=2)
			maze[i][j] = num[1].val, -- num[1].cnt;
		for(int i=1; i<=n; i+=2)
		for(int j=1; j<=n&&num[1].cnt; j+=2)
			maze[i][j] = num[1].val, -- num[1].cnt;
		/* step two: fill in all num */ ;
		int p = 2; // which num is dealt with
		for(int i=2; i<=n; i+=2)
		for(int j=1; j<=n&&p<=k; j+=2){
			if(maze[i][j]) continue;
			for(; !num[p].cnt; ++p)
				if(p == k+1) break;
			if(p != k+1){
				maze[i][j] = num[p].val;
				-- num[p].cnt;
			}
		}
		for(int i=1; i<=n; i+=2)
		for(int j=1; j<=n&&p<=k; j+=2){
			if(maze[i][j]) continue;
			for(; !num[p].cnt; ++p)
				if(p == k+1) break;
			if(p != k+1){
				maze[i][j] = num[p].val;
				-- num[p].cnt;
			}
		}
		for(int i=1; i<=n; i+=2)
		for(int j=2; j<=n&&p<=k; j+=2){
			for(; !num[p].cnt; ++p)
				if(p == k+1) break;
			if(p != k+1){
				maze[i][j] = num[p].val;
				-- num[p].cnt;
			}
		}
		printf("%d\n",n);
		/* step three: output */ ;
		for(int i=1; i<=n; ++i,puts(""))
		for(int j=1; j<=n; ++j){
			printf("%d ",maze[i][j]);
			maze[i][j] = 0; // clear
		}
	}

	return 0;
}

/*

black = (n*n+1)>>1

blank = (n>>1)*(n>>1)

free = black - blank

red = (n>>1)*((n+1)>>1)

*/