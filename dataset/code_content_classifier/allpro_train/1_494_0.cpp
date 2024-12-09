#include <bits/stdc++.h>
using namespace std;

using ll=int64_t;
#define int ll

#define FOR(i,a,b) for(int i=int(a);i<int(b);i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define REACH cerr<<"reached line "<<__LINE__<<endl
#define DMP(x) cerr<<"line "<<__LINE__<<" "<<#x<<":"<<x<<endl
#define ZERO(x) memset(x,0,sizeof(x))

using pi=pair<int,int>;
using vi=vector<int>;
using ld=long double;

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"[";
	REP(i,(int)v.size()){
		if(i)os<<",";
		os<<v[i];
	}
	os<<"]";
	return os;
}

int read(){
	int i;
	scanf("%" SCNd64,&i);
	return i;
}

void printSpace(){
	printf(" ");
}

void printEoln(){
	printf("\n");
}

void print(int x,int suc=1){
	printf("%" PRId64,x);
	if(suc==1)
		printEoln();
	if(suc==2)
		printSpace();
}

string readString(){
	static char buf[3341000];
	scanf("%s",buf);
	return string(buf);
}

char* readCharArray(){
	static char buf[3341000];
	static int bufUsed=0;
	char* ret=buf+bufUsed;
	scanf("%s",ret);
	bufUsed+=strlen(ret)+1;
	return ret;
}

template<class T,class U>
void chmax(T& a,U b){
	if(a<b)
		a=b;
}

template<class T,class U>
void chmin(T& a,U b){
	if(a>b)
		a=b;
}

template<class T>
T Sq(const T& t){
	return t*t;
}

const int inf=LLONG_MAX/3;

namespace Fast{

const int Nmax=200010;
int match[Nmax];
bool vis[Nmax];
bool Go(int n,const string&s){
	ZERO(vis);
	int pos=0;
	while(pos<n*2){
		pos=match[pos];
		vis[pos]=true;
		pos++;
	}
	REP(i,n*2-1)
		if((s[i]=='1')^vis[i])
			return false;
	return true;
}
void Match(int a,int b){
	match[a]=b;
	match[b]=a;
}
void Muri(){
	cout<<"No"<<endl;
	exit(0);
}
int col[Nmax];
void ShowMatch(int n){
	cout<<"Yes"<<endl;
	REP(i,n*2)col[i]=-1;
	int k=0;
	REP(i,n*2){
		if(col[i]==-1)
			col[i]=++k;
		col[match[i]]=col[i];
		print(col[i],i==n*2-1?1:2);
	}
}

bool Calc(int n,string s){
	//int n=read();
	//string s=string("1")+readString()+string("1");
	s=string("1")+s+string("1");
	REP(i,n*2)match[i]=-1;
	vi pos00,pos01,pos10,pos11;
	REP(i,n*2){
		if(s[i]=='0'){
			if(s[i+1]=='0'){
				pos00.PB(i);
			}else{
				pos01.PB(i);
			}
		}else if(s[i]=='1'){
			if(s[i+1]=='0'){
				pos10.PB(i);
			}else{
				pos11.PB(i);
			}
		}
	}
	if(int(pos00.size())%2==1){
		//Muri();
		return false;
	}
	for(int i=0;i<int(pos00.size());i+=2)
		Match(pos00[i],pos00[i+1]);
	if(int(pos11.size())%4==0){
		// do nothing
	}else{
		vi ss;
		int cur=0;
		REP(i,n*2+1)
			if(s[i]=='1'){
				cur++;
				if(i==n*2||s[i+1]=='0')
					ss.PB(cur);
			}else
				cur=0;
		if(int(ss.size())==1)
			return false;
		int cnt1=0,cnt2=0;
		FOR(i,1,int(ss.size())-1)
			if(ss[i]>1)cnt1++;
		if(ss[0]>1)cnt2++;
		if(ss.back()>1)cnt2++;
		if(cnt1==0||cnt1+cnt2<=1)
			return false;
		
		vector<vi> z;
		{
			vi w;
			int last=pos11.front()-1;
			for(auto p:pos11){
				if(last+1<p){
					z.PB(w);
					w.clear();
				}
				last=p;
				w.PB(p);
			}
			z.PB(w);
		}
		{
			int zs=z.size();
			int a,b;
			REP(i,zs)
				if(1<=z[i].front()&&z[i].back()<=n*2-2)
					a=i;
			REP(i,zs)
				if(a!=i)
					b=i;
			Match(z[a].front()-1,z[a].back()+1);
			pos01.erase(find(ALL(pos01),z[a].front()-1));
			pos10.erase(find(ALL(pos10),z[a].back()+1));
			Match(z[a].front(),z[b].back());
			z[b].pop_back();
			FOR(i,1,z[a].size())
				z[b].PB(z[a][i]);
			z[a].clear();
			//REACH;
			pos11.clear();
			for(auto zz:z)for(auto zzz:zz)
				pos11.PB(zzz);
		}
	}
	REP(i,pos01.size())
		Match(pos01[i],pos10[i]);
	assert(int(pos11.size())%4==0);
	for(int i=0;i<int(pos11.size());i+=4){
		Match(pos11[i],pos11[i+2]);
		Match(pos11[i+1],pos11[i+3]);
	}
	//REACH;
	//ShowMatch(n);
	return true;
}

}

namespace Slow{
	const int Nmax=20;
	int match[Nmax];
	bool vis[Nmax];
	bool Go(int n,const string&s){
		ZERO(vis);
		int pos=0;
		while(pos<n*2){
			pos=match[pos];
			vis[pos]=true;
			pos++;
		}
		REP(i,n*2-1)
			if((s[i]=='1')^vis[i])
				return false;
		return true;
	}
	bool rec(int n,string s){
		int a=find(match,match+n*2,-1)-match;
		if(a==n*2)
			return Go(n,s);
		FOR(b,a+1,n*2)if(match[b]==-1){
			match[a]=b;
			match[b]=a;
			if(rec(n,s))return true;
			match[a]=-1;
			match[b]=-1;
		}
		return false;
	}
	bool Calc(int n,string s){
		REP(i,n*2)match[i]=-1;
		return rec(n,s);
	}
}

void Test(int n,string s){
	bool s1=Fast::Calc(n,s);
	bool s2=Slow::Calc(n,s);
	//	cerr<<s1<<" "<<s2<<endl;
	if(s1!=s2){
		cerr<<"Fail"<<endl;
		cerr<<n<<endl;
		cerr<<s<<endl;
		cerr<<s1<<" "<<s2<<endl;
		exit(1);
	}
}

struct xorshift{
public:
	xorshift(){
		a = unsigned(clock());
		b = 1145141919;
		c =  810893334;
		d = 1919334810;
		REP(i,114)
			operator()();
	}
	unsigned operator()(){
		unsigned w = a ^ (a << 11);
		a=b;b=c;c=d;
		d=(d^(d>>19))^(w^(w>>8));
		return d;
	}
private:
	unsigned a,b,c,d;
} xrand;

int irand(int k){
	return xrand()%k;
}

int range(int b,int e){
	return b+irand(e-b);
}

void Ganbaru(int n){
	string s(n*2-1,'0');
	REP(i,n*2-1)s[i]='0'+irand(2);
	Test(n,s);
}

void Check(int n){
	string s(n*2-1,'0');
	REP(i,n*2-1)s[i]='0'+irand(2);
	bool ans=Fast::Calc(n,s);
	if(ans){
		assert(Fast::Go(n,s));
		//Fast::ShowMatch(n);
	}else{}
		//Fast::Muri();
}

signed main(){
	/*int n=read();
	REP(i,1000){
		cerr<<"Test "<<i<<endl;
		Ganbaru(n);
	}*/
	/*REP(i,100){
		cerr<<"Test "<<i<<endl;
		Check(100000);
	}*/
	int n=read();
	string s=readString();
	bool ans=Fast::Calc(n,s);
	if(ans){
		assert(Fast::Go(n,s));
		Fast::ShowMatch(n);
	}else
		Fast::Muri();
}