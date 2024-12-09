#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define REP1(i,n) for(int i=1;i<=n;++i)
#define ALL(c) (c).begin(),(c).end()
bool a[210][210];
typedef pair<int,int> P;
vector<P> num[13];		//0~9,+,-,.
void makenum(){
	num[0].push_back(P(0,0));
	num[0].push_back(P(0,1));
	num[0].push_back(P(0,2));
	num[0].push_back(P(0,3));
	num[0].push_back(P(0,4));
	num[0].push_back(P(1,0));
	num[0].push_back(P(1,4));
	num[0].push_back(P(2,0));
	num[0].push_back(P(2,1));
	num[0].push_back(P(2,2));
	num[0].push_back(P(2,3));
	num[0].push_back(P(2,4));
	num[1].push_back(P(0,0));
	num[1].push_back(P(0,1));
	num[1].push_back(P(0,2));
	num[1].push_back(P(0,3));
	num[1].push_back(P(0,4));
	num[2].push_back(P(0,0));
	num[2].push_back(P(0,2));
	num[2].push_back(P(0,3));
	num[2].push_back(P(0,4));
	num[2].push_back(P(1,0));
	num[2].push_back(P(1,2));
	num[2].push_back(P(1,4));
	num[2].push_back(P(2,0));
	num[2].push_back(P(2,1));
	num[2].push_back(P(2,2));
	num[2].push_back(P(2,4));
	num[3].push_back(P(0,0));
	num[3].push_back(P(0,2));
	num[3].push_back(P(0,4));
	num[3].push_back(P(1,0));
	num[3].push_back(P(1,2));
	num[3].push_back(P(1,4));
	num[3].push_back(P(2,0));
	num[3].push_back(P(2,1));
	num[3].push_back(P(2,2));
	num[3].push_back(P(2,3));
	num[3].push_back(P(2,4));
	num[4].push_back(P(0,0));
	num[4].push_back(P(0,1));
	num[4].push_back(P(0,2));
	num[4].push_back(P(1,2));
	num[4].push_back(P(2,0));
	num[4].push_back(P(2,1));
	num[4].push_back(P(2,2));
	num[4].push_back(P(2,3));
	num[4].push_back(P(2,4));
	num[5].push_back(P(0,0));
	num[5].push_back(P(0,1));
	num[5].push_back(P(0,2));
	num[5].push_back(P(0,4));
	num[5].push_back(P(1,0));
	num[5].push_back(P(1,2));
	num[5].push_back(P(1,4));
	num[5].push_back(P(2,0));
	num[5].push_back(P(2,2));
	num[5].push_back(P(2,3));
	num[5].push_back(P(2,4));
	num[6].push_back(P(0,0));
	num[6].push_back(P(0,1));
	num[6].push_back(P(0,2));
	num[6].push_back(P(0,3));
	num[6].push_back(P(0,4));
	num[6].push_back(P(1,0));
	num[6].push_back(P(1,2));
	num[6].push_back(P(1,4));
	num[6].push_back(P(2,0));
	num[6].push_back(P(2,2));
	num[6].push_back(P(2,3));
	num[6].push_back(P(2,4));
	num[7].push_back(P(0,0));
	num[7].push_back(P(1,0));
	num[7].push_back(P(2,0));
	num[7].push_back(P(2,1));
	num[7].push_back(P(2,2));
	num[7].push_back(P(2,3));
	num[7].push_back(P(2,4));
	num[8].push_back(P(0,0));
	num[8].push_back(P(0,1));
	num[8].push_back(P(0,2));
	num[8].push_back(P(0,3));
	num[8].push_back(P(0,4));
	num[8].push_back(P(1,0));
	num[8].push_back(P(1,2));
	num[8].push_back(P(1,4));
	num[8].push_back(P(2,0));
	num[8].push_back(P(2,1));
	num[8].push_back(P(2,2));
	num[8].push_back(P(2,3));
	num[8].push_back(P(2,4));
	num[9].push_back(P(0,0));
	num[9].push_back(P(0,1));
	num[9].push_back(P(0,2));
	num[9].push_back(P(0,4));
	num[9].push_back(P(1,0));
	num[9].push_back(P(1,2));
	num[9].push_back(P(1,4));
	num[9].push_back(P(2,0));
	num[9].push_back(P(2,1));
	num[9].push_back(P(2,2));
	num[9].push_back(P(2,3));
	num[9].push_back(P(2,4));
	num[10].push_back(P(1,-1));
	num[10].push_back(P(1,0));
	num[10].push_back(P(1,1));
	num[10].push_back(P(2,0));
	num[10].push_back(P(0,0));
	num[11].push_back(P(0,0));
	num[11].push_back(P(1,0));
	num[11].push_back(P(2,0));
	num[12].push_back(P(0,0));
	//8069235471+-.
}
int main(){
	makenum();		//yamipoyo
	int n;
	cin >> n;
	rep(i,n){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1==x2){
			if(y1>y2) swap(y1,y2);
			for(int j=y1;j<=y2;j++) a[x1][j]=true;
		}else{
			if(x1>x2) swap(x1,x2);
			for(int j=x1;j<=x2;j++) a[j][y1]=true;
		}
	}
	int numn=0,pro=1,ans=0;
	bool plus=true;
	rep(i,200){
		rep(j,200){
			if(!a[i][j]) continue;
			int type=-1;
			if(!a[i+1][j]){//14.
				if(!a[i][j+1]){//.
					type=12;
				}else{
					if(a[i][j+3]){//1
						type=1;
					}else{//4
						type=4;
					}
				}
			}else{//02356789+-
				if(a[i+1][j+1]){//+
					type=10;
				}else{//02356789-
					if(!a[i][j+1] && !a[i+2][j+1]){//-
						type=11;
					}else{//02356789
						if(a[i][j+1]){//05689
							if(!a[i+1][j+2]){//0
								type=0;
							}else{
								if(a[i][j+3]){//68
									if(a[i+2][j+1]) type=8;
									else type=6;
								}else{
									if(a[i+2][j+1]){//9
										type=9;
									}else{//5
										type=5;
									}
								}
							}
						}else{//237
							if(!a[i][j+2]){//7
							type=7;
							}else{
								if(a[i][j+3]){//2
									type=2;
								}else{//3
									type=3;
								}
							}
						}
					}
				}
			}
			rep(k,num[type].size()) a[i+num[type][k].first][j+num[type][k].second]=false;
//			cout << type << " " << i << " " << j << endl;
			if(type<10){
				numn=numn*10+type;
			}
			if(type==10){
				pro*=numn;
				if(plus) ans+=pro;
				else ans-=pro;
				plus=true;
				numn=0;
				pro=1;
			}
			if(type==11){
				pro*=numn;
				if(plus) ans+=pro;
				else ans-=pro;
				plus=false;
				numn=0;
				pro=1;
			}
			if(type==12){
				pro*=numn;
				numn=0;
			}
//			cout << numn << " " << pro << " " << ans << endl;
		}
	}
	pro*=numn;
	if(plus) ans+=pro;
	else ans-=pro;
	cout << ans << endl;
	return 0;
}
