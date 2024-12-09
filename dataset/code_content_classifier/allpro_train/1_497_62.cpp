#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef pair<int , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define Fst first
#define Snd second
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)
#define repv(t,it,v) for(vector<t>::iterator it = v.begin() ; it != v.end() ; ++it)

typedef long long LL;

int H , W;
int a[222][222];
LL dp[444][222][222];

int main(){
	scanf("%d%d" , &H , &W);
	repp(i,1,H+1){
		repp(j,1,W+1){
			scanf("%d" , &a[i][j]);
		}
	}
	int n = H + W + 1;
	dp[2][1][1] = a[1][1];
	repp(i,3,n){
		int x = max(1,i-W);
		int y = min(i,H+1);
		repp(j,x,y){
			repp(k,x,y){
				dp[i][j][k] = max(max(dp[i-1][j-1][k] , dp[i-1][j][k]) , max(dp[i-1][j-1][k-1] , dp[i-1][j][k-1])) + a[j][i-j] + (j != k ? a[k][i-k] : 0);
			}
		}
	}
	printf("%lld\n" , dp[H+W][H][H]);
	return 0;
}
