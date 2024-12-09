#include<map>
#include<string>
#include<vector>
#include<complex>
#include<iostream>

#define	pb	push_back

using namespace std;

typedef	complex<int>	P;

const int dx[]={1,1,0,-1,-1,-1,0,1},dy[]={0,1,1,1,0,-1,-1,-1};

int w,h;
string pic[1000];

void trace(const P &p,vector<P> &v,int bef){
	int x=p.real(),y=p.imag();
	pic[y][x]='+';
	for(int i=0;i<8;i++){
		int xx=x+dx[i],yy=y+dy[i];
		if(0<=xx && xx<w && 0<=yy && yy<h && pic[yy][xx]=='*'){
			if(i!=bef)	v.pb(P(x,y));
			trace(P(xx,yy),v,i);
			break;
		}
	}
}

int main(){
	w=80;
	for(int t=0;cin>>h,h;t++){
		cin.ignore();
		for(int i=0;i<h;i++){
			getline(cin,pic[i]);
			pic[i]+=string(w-pic[i].length(),' ');
		}

		map<int,int> acnt;
		for(int i=0;i<h;i++)for(int j=0;j<w;j++){
			if(pic[i][j]=='*'){
				vector<P> v;
				trace(P(j,i),v,-1);
				int ub=v[1].real()-v[0].real()+1;
				int lb=v[2].real()-v[3].real()+1;
				int hh=v[2].imag()-v[0].imag()+1;
				acnt[(ub+lb)*hh/2]++;
			}
		}

		map<int,int>::iterator it;
		if(t)	cout<<"----------"<<endl;
		for(it=acnt.begin();it!=acnt.end();it++){
			cout<<it->first<<' '<<it->second<<endl;
		}
	}

	return 0;
}